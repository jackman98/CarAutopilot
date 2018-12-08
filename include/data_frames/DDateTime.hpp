#ifndef DDATETIME_HPP
#define DDATETIME_HPP

#pragma once

#include <string>
#include "GlobalPrimitives.hpp"

namespace v2x {
namespace frame {

class CDDateTime   /* SEQUENCE */
{
public:
    CDDateTime();
    CDDateTime(const CDDateTime &);
    CDDateTime(element::yearType year_val, element::monthType month_val, element::dayType day_val,
               element::hourType hour_val, element::minuteType minute_val, element::secondType second_val,
               element::offsetType offset_val);
    ~CDDateTime();

    CDDateTime & operator = (const CDDateTime &);
    int operator == (const CDDateTime &) const;
    int operator != (const CDDateTime &) const;

    // year *get_year();
    // const year *get_year() const;
    // void set_year(year);
    // int year_is_present() const;
    // void omit_year();

    element::yearType get_year() const;
    // const year *get_year() const;
    void set_year(element::yearType);
    int year_is_present() const;
    void omit_year();

    element::monthType *get_month();
    const element::monthType *get_month() const;
    void set_month(element::monthType);
    int month_is_present() const;
    void omit_month();

    element::dayType *get_day();
    const element::dayType *get_day() const;
    void set_day(element::dayType);
    int day_is_present() const;
    void omit_day();

    element::hourType *get_hour();
    const element::hourType *get_hour() const;
    void set_hour(element::hourType);
    int hour_is_present() const;
    void omit_hour();

    element::minuteType *get_minute();
    const element::minuteType *get_minute() const;
    void set_minute(element::minuteType);
    int minute_is_present() const;
    void omit_minute();

    element::secondType *get_second();
    const element::secondType *get_second() const;
    void set_second(element::secondType);
    int second_is_present() const;
    void omit_second();

    element::offsetType *get_offset();
    const element::offsetType *get_offset() const;
    void set_offset(element::offsetType);
    int offset_is_present() const;
    void omit_offset();
private:
    uint32_t bit_mask;
    element::yearType year_field;
    element::monthType month_field;
    element::dayType day_field;
    element::hourType hour_field;
    element::minuteType minute_field;
    element::secondType second_field;
    element::offsetType offset_field;
};

}; //v2x
}; //frame

#endif
