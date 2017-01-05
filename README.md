SImple Kalman Filter Library
========================================

 ![KalmanFilter](images/kalman_filter_example_1.png)

This is a basic kalman filter library for single variable models, like barometric sensors, temperature sensors and any stream of values that do not requires a multidimensional model.

* Take a look in this [video on youtube](https://www.youtube.com/watch?v=4Q5kJ96YYZ4) to see the Kalman Filter working on a stream of values!
 
 Repository Contents
-------------------

* **/examples** - Example sketches for the library (.ino). Run these from the Arduino IDE. 
* **/src** - Source files for the library (.cpp, .h).
* **keywords.txt** - Keywords from this library that will be highlighted in the Arduino IDE. 
* **library.properties** - General library properties for the Arduino package manager. 


Basic Usage
-------------------
 * e_mea: Measurement Uncertainty - How much do we expect to our measurement vary 
 * e_est: Estimation Uncertainty  - How much our estimate starts off the value (can be initilized with the same value as e_mea)
 * q: Process Noise, usually a small number between 0.001 and 1 - how fast your measurement moves. Recommended 0.01.
 
```c++

 SimpleKalmanFilter kf = SimpleKalmanFilter(e_mea, e_est, q);

 while (1) {
  float x = analogRead(A0);
  float estimated_x = kf.updateEstimate(x);
  
  // ...
 } 

``` 
 
Example Briefs
--------------

* BasicKalmanFilterExample - A basic example reading a value from a potentiometer in A0 and SimpleKalmanFilter class to generate estimates.
* AltitudeKalmanFilterExample - Uses a BMP180 barometric sensor and the SimpleKalmanFilter class to estimate the correct altitude.


Additional Documentation
-------------------------

* **[Installing Additional Arduino Libraries](https://www.arduino.cc/en/Guide/Libraries)** - Basic information on how to install an Arduino library.


Version History
---------------

* [V 0.1.0](https://github.com/denyssene/SimpleKalmanFilter) -- Initial commit


License Information
-------------------

This is an _**open source**_ project! 

Please review the LICENSE.md file for license information. 

If you have any questions or concerns on licensing, please contact denys.sene@gmail.com.
