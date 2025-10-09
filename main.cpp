#define CROW_MAIN

#include "crow_all.h"
#include <iostream>
using namespace std;
using namespace crow;


//Function prototypes for sending different types of files
void sendStyle(crow::response& res, std::string filename); //sending CSS files
void sendImage(crow::response& res, std::string filename); //Send images 
void sendScript(crow::response& res, std::string filename); //send Javascript files
void sendFile(crow::response& res, std::string filename, std::string contentType); //generic file sender
void sendHtml(crow::response& res, std::string filename); //send html files
void logTransaction(char* buf); // log transactions if needed

int main()
{
	std::ofstream logStream("../public/log.txt"); // reset log data
	logStream.close();

	//Create web application and socket
	SimpleApp app;
	
	// index root route
	CROW_ROUTE(app, "/").methods(crow::HTTPMethod::POST, crow::HTTPMethod::GET)([](const crow::request& req, crow::response& res) {
		sendHtml(res, "index");
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

//Function to save transaction data to a file
void logTransaction(char* buf) {
	std::ofstream out("../public/log.txt");
	std::string s = std::string(buf);
	out << s.c_str() << std::endl; //writing data
	out.close();
}
