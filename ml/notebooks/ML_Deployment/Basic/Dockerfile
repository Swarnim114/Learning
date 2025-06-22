# Use official Python slim image for a smaller footprint
FROM python:3.12-slim

# Set working directory
WORKDIR /app

# Copy project files
COPY app.py streamlit_app.py linear_model.pkl requirements.txt ./

# Install dependencies
RUN pip install --no-cache-dir -r requirements.txt

# Expose ports for Flask and Streamlit
EXPOSE 5000 8501

# Run both Flask and Streamlit
CMD ["sh", "-c", "python app.py & streamlit run streamlit_app.py --server.port 8501"]