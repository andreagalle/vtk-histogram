#ifndef __histogramArgs_h
#define __histogramArgs_h

#include <string>
#include <stdexcept>

/**
 * @brief hold the results of command line argument parsing.
 */
struct Args
{
  std::string inputImage;
  bool minValueWasSet;
  bool maxValueWasSet;
  double minValue;
  double maxValue;
  unsigned int numBins;

  Args( int argc, char* argv[] );

  // Just so we can distinguish it.
  class got_xml_flag_exception: public std::logic_error
    {
    public:
      got_xml_flag_exception( const std::string& what ): std::logic_error( what ) {}
    };
};

#endif
