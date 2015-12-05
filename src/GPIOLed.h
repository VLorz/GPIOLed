#ifndef  _LED_h_
#define  _LED_h_


#include <inttypes.h>
#include <Arduino.h>



typedef enum {
  GPIOLEDMODE_MANUAL,
  GPIOLEDMODE_BLINKING,
} GPIOLed_mode_t;


class GPIOLed
{
  public:
    GPIOLed( int Output );
    
    void on();
    void off();
    void blink( int delay );
    void blink( int OnTime, int OffTime );
    bool blinking() { return (m_Mode == GPIOLEDMODE_BLINKING); }
    
    void update();
    
    int state() { return m_State; };
  
  private:
    int m_Output;
    int m_State;
    unsigned long m_ToggleTime;
    int m_OnTime;
    int m_OffTime;
    GPIOLed_mode_t m_Mode;
};



#endif  /* _LED_h_ */

