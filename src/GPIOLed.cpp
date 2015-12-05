#include "GPIOLed.h"
#include <arduino.h>


GPIOLed::GPIOLed(  int Output  )
  : m_Output( Output ), m_Mode( GPIOLEDMODE_MANUAL ), m_State( LOW ), m_ToggleTime( 0 )
{
  if (m_Output >=0)
  {
    pinMode( m_Output, OUTPUT );
    digitalWrite( m_Output, m_State );
  }
}


void GPIOLed::on()
{
  if (m_Output >=0)
  {
    m_Mode = GPIOLEDMODE_MANUAL;
    digitalWrite( m_Output, m_State = HIGH );
    m_ToggleTime = millis();
  }
}

void GPIOLed::off()
{
  if (m_Output >=0)
  {
    m_Mode = GPIOLEDMODE_MANUAL;
    digitalWrite( m_Output, m_State = LOW );
    m_ToggleTime = millis();
  }
}

void GPIOLed::blink( int delay )
{
  blink( delay, delay );
}

void GPIOLed::blink( int OnTime, int OffTime )
{
  if (m_Output >=0)
  {
    m_OnTime = OnTime;
    m_OffTime = OffTime;
    
    m_Mode = GPIOLEDMODE_BLINKING;
    digitalWrite( m_Output, m_State = HIGH );
    m_ToggleTime = millis();
  }
}


void GPIOLed::update()
{
  unsigned long Elapsed = millis() - m_ToggleTime;
  
  if (m_Output < 0)
    return;
    
  if (m_Mode == GPIOLEDMODE_BLINKING)
  {
    if (m_State == LOW)
    {
      if (Elapsed >= m_OffTime)
      {
        digitalWrite( m_Output, m_State = HIGH );
        m_ToggleTime = millis();
      }
    }
    else
    {
      if (Elapsed >= m_OnTime)
      {
        digitalWrite( m_Output, m_State = LOW );
        m_ToggleTime = millis();
      }
    }
  }
}

