#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <map>
#include <algorithm>
#include <exception>

using namespace std;

class Location {
public:
    string name;
    double latitude;
    double longitude;

    Location(const string& name, double latitude, double longitude)
        : name(name), latitude(latitude), longitude(longitude) {}
};

class LocationManager {
private:
    vector<Location> locations;

public:
    void addLocation(const string& name, double latitude, double longitude) {
        locations.push_back(Location(name, latitude, longitude));
    }

    void removeLocation(const string& name) {
        locations.erase(remove_if(locations.begin(), locations.end(),
            [&name](const Location& loc) { return loc.name == name; }),
            locations.end());
    }

    void listLocations() const {
        for (const auto& loc : locations) {
            cout << "Name: " << loc.name << ", Latitude: " << loc.latitude << ", Longitude: " << loc.longitude << endl;
        }
    }
};

class WeatherVariable {
public:
    string variableName;
    double value;

    WeatherVariable(const string& variableName, double value)
        : variableName(variableName), value(value) {}
};

class WeatherVariableManager {
private:
    vector<WeatherVariable> variables;

public:
    void addVariable(const string& variableName, double value) {
        variables.push_back(WeatherVariable(variableName, value));
    }

    void listVariables() const {
        for (const auto& var : variables) {
            cout << "Variable: " << var.variableName << ", Value: " << var.value << endl;
        }
    }
};

// Class for both weather and air quality systems
class DataFetchingSystem {
protected:
    string apiKey;
    string baseUrl;

public:
    DataFetchingSystem(const string& apiKey, const string& baseUrl)
        : apiKey(apiKey), baseUrl(baseUrl) {}

    virtual string fetchData(const string& endpoint, const map<string, string>& params) {
        return "API response"; // Mock API call
    }

    virtual void handleApiResponse(const string& response) = 0;
};

// Weather Forecasting System
class WeatherForecastingSystem : public DataFetchingSystem {
public:
    WeatherForecastingSystem(const string& apiKey, const string& baseUrl)
        : DataFetchingSystem(apiKey, baseUrl) {}

    string fetchForecast(const Location& location) {
        return "Mock Forecast data for " + location.name;
    }

    void handleApiResponse(const string& response) override {
        cout << response << endl;
    }
};

// Historical Weather System
class HistoricalWeatherSystem : public DataFetchingSystem {
public:
    HistoricalWeatherSystem(const string& apiKey, const string& baseUrl)
        : DataFetchingSystem(apiKey, baseUrl) {}

    string fetchHistoricalData(const Location& location, const string& startDate, const string& endDate) {
        return "Mock Historical data for " + location.name + " from " + startDate + " to " + endDate;
    }

    void handleApiResponse(const string& response) override {
        cout << response << endl;
    }
};

// Data export functionality
class DataExporter {
public:
    static void exportToCSV(const string& data, const string& filename) {
        ofstream file(filename);
        file << data;
        file.close();
    }

    static void exportToJSON(const string& data, const string& filename) {
        ofstream file(filename);
        file << "{\"data\":\"" << data << "\"}";
        file.close();
    }
};

// Cloud storage system and offline support
class CloudStorageSystem {
private:
    bool isOffline;
    string cloudServiceCredentials;

public:
    CloudStorageSystem(const string& cloudServiceCredentials, bool isOffline = false)
        : cloudServiceCredentials(cloudServiceCredentials), isOffline(isOffline) {}

    void saveLocally(const string& data) {
        ofstream file("local_data.txt");
        file << data;
        file.close();
    }

    string retrieveLocally() {
        ifstream file("local_data.txt");
        string data((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
        return data;
    }

    void setOfflineMode(bool offline) {
        isOffline = offline;
    }

    bool getOfflineMode() const {
        return isOffline;
    }
};

// User interface class for user interaction
class UserInterface {
public:
    string getUserInput() {
        string input;
        getline(cin, input);
        return input;
    }

    void handleExceptions(const exception& ex) {
        cerr << "Error: " << ex.what() << endl;
    }
};

int main() {
    LocationManager locationManager;
    WeatherVariableManager weatherVariableManager;
    WeatherForecastingSystem weatherForecastingSystem("api_key", "https://api.weather.com");
    HistoricalWeatherSystem historicalWeatherSystem("api_key", "https://api.weather.com");
    CloudStorageSystem cloudStorageSystem("cloud_credentials");
    UserInterface ui;

    while (true) {
        cout << "Menu:\n";
        cout << "1. Add Location\n";
        cout << "2. List Locations\n";
        cout << "3. Add Weather Variable\n";
        cout << "4. List Weather Variables\n";
        cout << "5. Fetch Weather Forecast\n";
        cout << "6. Fetch Historical Weather Data\n";
        cout << "7. Export Data to CSV\n";
        cout << "8. Export Data to JSON\n";
        cout << "9. Toggle Offline Mode\n";
        cout << "10. Exit\n";
        cout << "Enter choice: ";
        string choice = ui.getUserInput();

        try {
            if (choice == "1") {
                cout << "Enter location name: ";
                string name = ui.getUserInput();
                cout << "Enter latitude: ";
                double latitude;
                cin >> latitude;
                cout << "Enter longitude: ";
                double longitude;
                cin >> longitude;
                cin.ignore(); // To consume the newline after input
                locationManager.addLocation(name, latitude, longitude);
            }
            else if (choice == "2") {
                locationManager.listLocations();
            }
            else if (choice == "3") {
                cout << "Enter weather variable name: ";
                string variableName = ui.getUserInput();
                cout << "Enter value: ";
                double value;
                cin >> value;
                cin.ignore(); // To consume the newline
                weatherVariableManager.addVariable(variableName, value);
            }
            else if (choice == "4") {
                weatherVariableManager.listVariables();
            }
            else if (choice == "5") {
                cout << "Enter location name for forecast: ";
                string locationName = ui.getUserInput();
                Location location(locationName, 0.0, 0.0); // Mock latitude and longitude
                string forecast = weatherForecastingSystem.fetchForecast(location);
                weatherForecastingSystem.handleApiResponse(forecast);
            }
            else if (choice == "6") {
                cout << "Enter location name for historical data: ";
                string locationName = ui.getUserInput();
                cout << "Enter start date (YYYY-MM-DD): ";
                string startDate = ui.getUserInput();
                cout << "Enter end date (YYYY-MM-DD): ";
                string endDate = ui.getUserInput();
                Location location(locationName, 0.0, 0.0); // Mock latitude and longitude
                string historicalData = historicalWeatherSystem.fetchHistoricalData(location, startDate, endDate);
                historicalWeatherSystem.handleApiResponse(historicalData);
            }
            else if (choice == "7") {
                cout << "Enter data to export: ";
                string data = ui.getUserInput();
                cout << "Enter filename for CSV: ";
                string filename = ui.getUserInput();
                DataExporter::exportToCSV(data, filename);
            }
            else if (choice == "8") {
                cout << "Enter data to export: ";
                string data = ui.getUserInput();
                cout << "Enter filename for JSON: ";
                string filename = ui.getUserInput();
                DataExporter::exportToJSON(data, filename);
            }
            else if (choice == "9") {
                bool offline = cloudStorageSystem.getOfflineMode();
                cloudStorageSystem.setOfflineMode(!offline);
                cout << "Offline mode is now " << (!offline ? "enabled" : "disabled") << endl;
            }
            else if (choice == "10") {
                break;
            }
            else {
                cout << "Invalid choice, please try again." << endl;
            }
        }
        catch (const exception& ex) {
            ui.handleExceptions(ex);
        }
    }

    return 0;
}
