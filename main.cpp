#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

unordered_map<string, string> chatbot_responses = {
    {"academia", "Please contact the IT support team."},
    {"moodle", "Try clearing the browser cache or contact the IT department."},
    {"result", "Please check the university portal or contact the examination office at A Block 4th Floor."},
    {"issue book", "Visit the library, present your ID card, and request the book."},
    {"transport", "Contact the transport office for the procedure to avail transportation."},
    {"kiec", "KIEC is located in basement of Block C."},
    {"examination", "It is located on the 4th floor at A block."},
    {"library", "The library is located in Block A in Basement."},
    {"accounts", "The accounts office is located on the ground floor of Block A."},
    {"registrar", "The registrar office is located in Block A, opposite the library."},
    {"admission", "You can apply for admission online through the university website. https://admissions.krmangalam.edu.in/"},
    {"stationary", "The stationary shop is located next to the main entrance."},
    {"hostel", "The hostel is located behind Block C."},
    {"sports", "The sports playground is located beside the hostel."},
    {"fees", "You can access the fee payment QR code from the university payment portal."},
    {"scholarship", "Yes, there are various scholarships available for meritorious students."},
    {"placement", "The job placement rate is approximately 80%."},
    {"dress code", "Students are required to wear formal attire for lectures."},
    {"college timings", "College timings are from 9 AM to 4 PM."},
    {"medical room", "The medical room is located near the sports complex in Block B."},
    {"anti ragging", "You can get the Anti-Ragging form from the student welfare office."},
    {"timetable", "You can get the timetable from the university portal."},
    {"result", "You can check your result via the student portal."},
};

string get_response(const string& query) {
    string query_lower = query;
    transform(query_lower.begin(), query_lower.end(), query_lower.begin(), ::tolower);

    for (const auto& pair : chatbot_responses) {
        if (query_lower.find(pair.first) != string::npos) {
            return pair.second;
        }
    }

    return "Sorry, I could not understand your query.";
}

int main() {
    string user_query;
    cout << "Welcome to Samadhaan Chatbot! Type 'exit' to quit.\n";

    while (true) {
        cout << "Enter your query: ";
        getline(cin, user_query);
        
        if (user_query == "exit") {
            break;
        }
        
        cout << get_response(user_query) << endl;
    }

    return 0;
}
