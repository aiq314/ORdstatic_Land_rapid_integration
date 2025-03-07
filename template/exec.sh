#!/bin/bash

# Define the path to the executable and the log file
EXECUTABLE="/home/ali/CiPAORdv1.0_Land_rapid_integration/bin/cipaordv1_land2016"
PARAMS_FILE="params.txt"
HILL_DATA_FILE="/home/ali/CiPAORdv1.0_Land_rapid_integration/hill_data/bepridil.csv"
LOG_FILE="simulation.log"

# Check if the executable and parameter files exist
if [[ ! -f "$EXECUTABLE" || ! -f "$PARAMS_FILE" || ! -f "$HILL_DATA_FILE" ]]; then
    echo "Error: One or more required files are missing."
    exit 1
fi

# Delete some previous results
rm -rf *.log *.plt

# Run the simulation and redirect output to log file
$EXECUTABLE $PARAMS_FILE $HILL_DATA_FILE> $LOG_FILE 2>&1
