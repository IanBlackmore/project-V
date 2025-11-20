# Transactions-API

## Table of Contents

* [Project Overview](#project-overview)
* [Install & Build](#install-&-build)
* [API Route](#api-route)

## Project Overview

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
