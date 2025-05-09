 # ML-HealthAssistant 🧠
 
An AI-Powered Personalized Medical Recommendation System 💡

🌟 Overview
ML-HealthAssistant is the machine learning engine behind the SmartHealth IoT Monitoring System. It leverages health vitals and symptom data to predict potential diseases, recommend personalized medications, and provide tailored fitness and diet plans. With an intuitive web interface powered by Flask, the system helps users manage and improve their health, enabling proactive disease detection and wellness strategies.
The system works both as a stand-alone solution and can be integrated with IoT sensors to provide real-time monitoring and recommendations. 🌍💪
![project3](https://github.com/user-attachments/assets/e242a44d-fec0-4a1c-8bd2-cd40b5ed83b7)


📊 Technologies Used

1. Python 3.x 🐍

2. Flask 🌐

3. scikit-learn 📚

4. pandas, NumPy 🔢

5. HTML/CSS (for UI) 🎨

📁 Folder Structure

1. disease_prediction.py – Main script to predict disease based on input data

2. medication_recommender.py – Provides top medicine suggestions per condition

3. diet_fitness_suggester.py – Recommends health routines based on diagnosis

4. preprocessing.py – Prepares and cleans incoming data

5. app.py – Flask web application for user interaction

6. templates/ – HTML templates for web interface

7. model.pkl – Pre-trained machine learning model

8. requirements.txt – Dependencies to run the system

# Key Features
1. Intelligent Disease Prediction
Predicts the most likely illness using machine learning models trained on health data and user symptoms.

2. Personalized Medication Advice
Recommends the top 5 relevant medicines with dosage information and precautionary notes.

3. Diet & Fitness Guidance
Suggests personalized workout routines and diet plans to support recovery and well-being.

4. Flask Web Interface
User-friendly interface for symptom entry and result display. Accessible via browser on any device.

5. Data Privacy
Processes user data locally with no personal data stored — privacy-first by design.



# How It Works
1. User Input
Users input symptoms (such as fever, cough, headache, etc.) through the web interface. Optionally, real-time vitals like temperature, heart rate, and blood pressure can be provided via IoT sensor integration.

2. Data Preprocessing
The input data is cleaned, scaled, and encoded to ensure compatibility with the machine learning model. This process includes handling missing data, standardizing values, and encoding categorical symptoms for better model prediction.

3. Disease Prediction
The system uses a trained machine learning model (such as Random Forest, Logistic Regression, or another classification algorithm) to analyze the processed data. Based on the input symptoms and vitals, the model predicts the most likely disease. It compares the entered data with patterns in the training dataset to output the most probable diagnosis. The model returns a list of potential diseases, ranked by their likelihood.

4. Medication Recommendations
Based on the predicted disease, the medication_recommender.py script suggests the top 5 relevant medications. These are tailored to the specific illness, considering factors like common treatments and the user’s general health. For each medication, the script provides dosage instructions and potential side effects or precautions to consider.

5. Personalized Diet & Fitness Guidance
The diet_fitness_suggester.py script generates personalized diet and fitness plans based on the predicted disease. For example, if the model predicts a disease like diabetes or hypertension, the script will recommend appropriate foods, meal timings, and types of exercises to help manage the condition. The recommendations are customized to help the user recover and maintain their overall well-being.

6. Web Output
All the results — disease prediction, medication recommendations, and health advice — are displayed on the Flask web interface in an easy-to-read format, allowing the user to take immediate action.

![project 4](https://github.com/user-attachments/assets/ac37bb81-74f5-4a4f-b161-781a8c2f5972)

