#include <SimpleKalmanFilter.h>

/*
 This sample code demonstrates how to use the SimpleKalmanFilter object. 
 Use a potentiometer in Analog input A0 as a source for the reference real value.
 Some random noise will be generated over this value and used as a measured value.
 The estimated value obtained from SimpleKalmanFilter should match the real
 reference value.

 SimpleKalmanFilter(e_mea, e_est, q);
 e_mea: Measurement Uncertainty 
 e_est: Estimation Uncertainty 
 q: Process Noise
 */
SimpleKalmanFilter simpleKalmanFilter(2, 2, 0.01);

// Serial output refresh time
const long SERIAL_REFRESH_TIME = 100;
long refresh_time;

void setup() {
  Serial.begin(115200);
}

void loop() {

  // read a reference value from A0 and map it from 0 to 100
  float real_value = analogRead(A0)/1024.0 * 100.0;
  
  // add a noise to the reference value and use as the measured value
  float measured_value = real_value + random(-100,100)/100.0;

  // calculate the estimated value with Kalman Filter
  float estimated_value = simpleKalmanFilter.updateEstimate(measured_value);

  // send to Serial output every 100ms
  // use the Serial Ploter for a good visualization
  if (millis() > refresh_time) {
    Serial.print(real_value,4);
    Serial.print(",");
    Serial.print(measured_value,4);
    Serial.print(",");
    Serial.print(estimated_value,4);
    Serial.println();
    
    refresh_time = millis() + SERIAL_REFRESH_TIME;
  }

}