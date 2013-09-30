//
//  rtmlexception.h
//  mhmm
//
//  Created by Jules Francoise on 12/06/13.
//
//

#ifndef mhmm_rtmlexception_h
#define mhmm_rtmlexception_h

#include <iostream>
#include <string>
#include <sstream>
#include <exception>

class RTMLException : public std::exception
{
public:
    RTMLException(std::string message="", std::string file="", std::string func="", int line=-1)
    {
        std::ostringstream oss;
#ifdef DEBUG
        oss << "Exception: file '" << file << "', function '" << func << "', line " << line << ":\n\t";
#endif
        oss << message;
        this->msg = oss.str();
    }
    
    RTMLException(RTMLException const& src)
    {
        this->_copy(this, src);
    }
    
    RTMLException& operator=(RTMLException const& src)
    {
        if(this != &src)
        {
            _copy(this, src);
        }
        return *this;
    }
    
    virtual void _copy(RTMLException *dst,
              RTMLException const& src)
    
    {
        dst->msg = src.msg;
    }
    
    virtual ~RTMLException() throw()
    {
        
    }
    
    virtual const char * what() const throw()
    {
        return this->msg.c_str();
    }
    
private:
    std::string msg;
};

#endif
