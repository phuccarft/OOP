#include "httplib.h"   
#include "json.hpp"    
#include "Library.h"   
#include "Student.h"  
#include "Teacher.h"   
#include <iostream>

using json = nlohmann::json;
using namespace httplib;
Library myLibrary;

int main(void) {
    Server svr;
    svr.set_default_headers({
        { "Access-Control-Allow-Origin", "*" },
        { "Access-Control-Allow-Methods", "POST, GET, OPTIONS" },
        { "Access-Control-Allow-Headers", "Content-Type" }
    });

    svr.Options("/add-member", [](const Request&, Response& res) {
        res.status = 204;
    });
    svr.Post("/add-member", [](const Request& req, Response& res) {
        json response_json;
        try {
            json data = json::parse(req.body);
            std::string name = data["name"];
            std::string id = data["id"];
            std::string type = data["type"];
            myLibrary.addMember(name, id, type);
            response_json["status"] = "success";
            response_json["message"] = "Đã thêm thành viên '" + name + "' vào C++ backend.";
            res.set_content(response_json.dump(), "application/json");

        } catch (const std::exception& e) {
            response_json["status"] = "error";
            response_json["message"] = e.what();
            res.status = 400;
            res.set_content(response_json.dump(), "application/json");
        }
    });
    std::cout << "Máy chủ C++ đang lắng nghe tại http://localhost:8080\n";
    svr.listen("0.0.0.0", 8080);
}