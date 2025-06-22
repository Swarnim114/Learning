import streamlit as st
import requests
import pandas as pd

st.title("California Housing Price Prediction")

# Input fields for California Housing features
med_inc = st.number_input("Median Income", min_value=0.0, max_value=15.0, value=3.0)
house_age = st.number_input("House Age", min_value=0, max_value=100, value=30)
ave_rooms = st.number_input("Average Rooms", min_value=0.0, max_value=50.0, value=5.0)
ave_bedrms = st.number_input("Average Bedrooms", min_value=0.0, max_value=10.0, value=1.0)
population = st.number_input("Population", min_value=0, max_value=10000, value=1000)
ave_occup = st.number_input("Average Occupancy", min_value=0.0, max_value=10.0, value=3.0)
latitude = st.number_input("Latitude", min_value=32.0, max_value=42.0, value=37.0)
longitude = st.number_input("Longitude", min_value=-124.0, max_value=-114.0, value=-122.0)

# Button to make prediction
if st.button("Predict"):
    # Prepare data for API
    data = {
        "MedInc": med_inc,
        "HouseAge": house_age,
        "AveRooms": ave_rooms,
        "AveBedrms": ave_bedrms,
        "Population": population,
        "AveOccup": ave_occup,
        "Latitude": latitude,
        "Longitude": longitude
    }
    # Call Flask API
    try:
        response = requests.post("http://localhost:5000/predict", json=data)
        prediction = response.json()['prediction']
        st.success(f"Predicted House Price: ${prediction * 100000:.2f}")
    except Exception as e:
        st.error(f"Error: {e}")