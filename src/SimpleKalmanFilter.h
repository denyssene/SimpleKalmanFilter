/*
 * SimpleKalmanFilter - a Kalman Filter implementation for single variable models.
 * Created by Denys Sene, January, 1, 2017.
 * Released under MIT License - see LICENSE file for details.
 */

#ifndef SimpleKalmanFilter_h
#define SimpleKalmanFilter_h

class SimpleKalmanFilter
{

public:
  SimpleKalmanFilter(float mea_e, float est_e, float q);
  float updateEstimate(float mea);
  void setMeasurementError(float mea_e);
  void setEstimateError(float est_e);
  void setProcessNoise(float q);
  float getKalmanGain();
  float getEstimateError();

private:
  float _err_measure;
  float _err_estimate;
  float _q;
  float _current_estimate = 0;
  float _last_estimate = 0;
  float _kalman_gain = 0;
};

#endif
