Historical Weather System

This C++ program provides a user-friendly interface for managing weather-related data, including locations, weather variables, and weather forecasting. The program is structured into multiple classes to handle different functionalities:

Location Management: The `Location` and `LocationManager` classes allow users to add, remove, and list locations with latitude and longitude data.

Weather Variables: The `WeatherVariable` and `WeatherVariableManager` classes manage weather-related variables like temperature, humidity, etc., and allow users to list these variables.

DataFetchingSystem: This base class is designed for fetching weather-related data from an external API (mocked in this code). It defines an interface for making API requests and handling responses.

WeatherForecastingSystem & HistoricalWeatherSystem: These classes extend `DataFetchingSystem` to fetch weather forecasts and historical weather data for specific locations. Each class implements a method to fetch data based on location and other parameters like dates.

Data Exporter: The `DataExporter` class provides functionality to export weather data to CSV and JSON file formats.

Cloud Storage & Offline Support: The `CloudStorageSystem` class manages cloud storage with support for offline mode, allowing data to be saved locally and retrieved later.

User Interface: The `UserInterface` class handles user input and error handling for the program. It manages a simple command-line menu that allows users to interact with the different functionalities of the system.

Main Program Loop: The main loop presents a menu of options to the user, including adding locations, fetching weather data, exporting data, and toggling offline mode. The user interacts with the program via the console.

This design is modular and extensible, making it suitable for future integration with real-world APIs for weather forecasting and storage systems.
