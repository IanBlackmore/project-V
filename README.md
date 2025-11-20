# Transactions-API

## Table of Contents

* [Project Overview](#project-overview)
* [Install & Build](#install-&-build)
* [API Route](#api-route)

## Project Overview

This project is a C++ application that proccess and reports fincial transactions using REST API routes using CROW. The application collects transactions data, categorizes revenue and cost, formats monetary values and generates a structed HTML report viewable through teh web interface.

The system runs in a Podman container and uses Boost ASIO and linux libraries. It includes compents for handling transactions, formatting currency values, updating budget and generating reports. 


## Install & Build


How to run:
```bash
run docker-compose up --build while in this directory for best results
```

Adding tests:
Follow formatting and update CMakeLists.txt accordingly
Update runCommands.sh to run your test executable before the project

## API Route

URL: http://localhost:23500/

```bash
Post /add_transaction/<double>/<string>/<string>
```
Double: Money in/Money Out 

String: Transactions details 

String: Team name 

Example
```bash
Post /add_transaction/-$4.50/burgur-bought/Menu-Team
```
