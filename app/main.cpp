#define CROW_MAIN

#include "crow_all.h"
#include "Transaction.h"
#include "TransactionAPI.h"
#include "TransactionReporter.h"
#include "MoneyFormatter.h"
#include <iostream>
using namespace std;
using namespace crow;


//Function prototypes for sending different types of files
void sendStyle(crow::response& res, std::string filename); //sending CSS files
void sendImage(crow::response& res, std::string filename); //Send images 
void sendScript(crow::response& res, std::string filename); //send Javascript files
void sendFile(crow::response& res, std::string filename, std::string contentType); //generic file sender
void sendHtml(crow::response& res, std::string filename); //send html files

int main()
{

	std::ofstream logStream("../public/log.txt"); // reset log data
	crow::mustache::set_global_base("../public/templates/");
	logStream.close();

	//Create web application and socket
	SimpleApp app;
	TransactionReporter reporter;
	TransactionAPI api;
	
	// index root route
	CROW_ROUTE(app, "/").methods(crow::HTTPMethod::GET)([](const crow::request& req, crow::response& res) {
		sendHtml(res, "index");
	});

	CROW_ROUTE(app, "/generate_report").methods(crow::HTTPMethod::GET)([&]() {
		
        auto page = crow::mustache::load("report.html");

        crow::mustache::context ctx;
        ctx["report"] = reporter.generateReport();
		
        return page.render(ctx);
	});

	//Mock Route for API transactions 
	CROW_ROUTE(app, "/add_transaction/<double>/<string>/<string>")
    .methods(crow::HTTPMethod::POST)
    ([&](const crow::request& req, crow::response& res,
         double moneyGain, std::string details, std::string teamName) {

        
		std::string response = api.generateTransaction(moneyGain, details, teamName);

		std::string invalidResponse = "Invalid";
		if (response == invalidResponse) {
			res.code = 409;
			double budget = TransactionAPI::getBudget();
			std::string errResponse = "Insufficient budget for this transaction\nTransaction denied\n";
			
			errResponse += "Current budget: " + MoneyFormatter::formatMoney(budget) + "\n";
			errResponse += "Your transaction cost: " + MoneyFormatter::formatMoney(moneyGain) + "\n";
			res.write(errResponse);
			res.end();
		}
		else {
			// TESTING CODE UNTIL DB GETS LINKED
			Transaction::counter++;
			Transaction t(moneyGain, details, teamName);
			reporter.addTransaction(t);
			
			// END OF TEST CODE, REPLACE WITH DB FUNCTIONALITY
			res.code = 200;
			res.write(response);
			res.end();
		}
    });


	//route for JS files	
	CROW_ROUTE(app, "/get_script/<string>") ([](const crow::request& req, crow::response& res, string filename) {
		sendScript(res, filename);
	});

	// get styles
	CROW_ROUTE(app, "/get_style/<string>") ([](const crow::request& req, crow::response& res, string filename) {
		sendStyle(res, filename);
	});
	
	// get images
	CROW_ROUTE(app, "/get_image/<string>") ([](const crow::request& req, crow::response& res, string filename) {
		sendImage(res, filename);
	});
	
	//Start webserver
	app.port(23500).multithreaded().run();
	return 1;
}

// send file from server function
void sendFile(crow::response& res, std::string filename, std::string contentType) {
	ifstream in("../public/" + filename, ifstream::in);
	if (in) {
		ostringstream contents;
		contents << in.rdbuf(); //Read file contents
		in.close(); 
		res.set_header("Content-Type", contentType); //set content type header
		res.write(contents.str()); //write file contents to response
	}
	else {
		res.code = 404; //file not found
		res.write("Not Found");
	}
	res.end();
}

// send html helper function
void sendHtml(crow::response& res, std::string filename) {
	sendFile(res, filename + ".html", "html");
}

// send style helper function
void sendStyle(crow::response& res, std::string filename) {
	sendFile(res, "styles/" + filename, "text/css");
}
// send image helper function
void sendImage(crow::response& res, std::string filename) {
	sendFile(res, "images/" + filename, "image/png");
}
// send script helper function
void sendScript(crow::response& res, std::string filename) {
	sendFile(res, "scripts/" + filename, "text/javascript");
}

//Function to save transaction data to a file (not necessary?)
//void logTransaction(char* buf) {
//	std::ofstream out("../public/log.txt");
//	std::string s = std::string(buf);
//	out << s.c_str() << std::endl; //writing data
//	out.close();
//}
