/*
 * Projet SV : Genomic
 * Raphael Reis Nunes & Marion Claudet
 * 2016
 */
#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <iostream>

/*!
 * @class Application
 *
 * @brief abstract class to manage the program
 *
 */
class Application
{
private:
  std::string fasta_name;  ///< Name of fasta file
  std::string pwm_name;    ///< Name of pwm file

public:
  /*!
   * @brief Constructor which asks for files' name.
   */
  Application();
  /*!
   * @brief Destructor
   */
  ~Application();

  /*!
   * @brief Match all application in ordrer to display characteristics of all sequencesmotifs.
   */
  void simulation();

};

#endif //APPLICATION_HPP
