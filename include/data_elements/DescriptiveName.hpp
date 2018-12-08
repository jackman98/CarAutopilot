#ifndef __DESCRIPTIVE_NAME_HPP__
#define __DESCRIPTIVE_NAME_HPP__

#include "DescriptiveName.h"
#include "V2XTypes.hpp"

/*
 * HUman readabble and recognizable name
 *
 * IA5String (SIZE ( 0 .. 63 ))
 */
namespace v2x {
namespace element {

class CDescriptiveName
{
public:
    CDescriptiveName();
    CDescriptiveName(DescriptiveName_t *value);
    CDescriptiveName(const char *str);
    CDescriptiveName(std::string &string);

    virtual ~CDescriptiveName();

    CDescriptiveName &operator=(CDescriptiveName &name);
  
    DescriptiveName_t *get() const;
    void set(DescriptiveName_t *value);

    std::string getString() const;
    int setString(const std::string &string);

    
private:
    DescriptiveName_t *_name;
};

} /* v2x */
} /* element */

#endif /* __DESCRIPTIVE_NAME_HPP__ */
