#include "Application.hpp"
#include "motif.h"
#include "fasta.hpp"
#include "PWM.h"
#include <iostream>
#include <fstream>

//Constructor which asks for files names'.
void Application::Application()
{
  std::cout << "Entrer le nom du fichier Fasta :" << std::endl;
  std::cin >> fasta_name >> std::endl;

  std::cout << "Entrer le nom du fichier PWM :" << std::endl;
  std::cin >> pwm_name >> std::endl;
}

//Destructor
void Application::~Application()
{}

//Match all application in ordrer to display characteristics of all sequences
//motifs.
void Application::simulation()
{
  PWM pwm(pwm_name);
  Motif motif;
  FastaReading reader;
  std::ofstream output("output.txt", std::ofstream::out);

  unsigned int motif_size(pwm.get_motif_size());

  //Iterate on sequence to read each motifs and give seq's charcteristics.
  for(unsigned int i(0); i < numberMotifs(&fasta_name, motif_size); ++i)
  {
    //Forward motif reading
    motif = reader.readseq(motif_size, fasta_name);


    //Display ex: sequence name + position on sequence + forward/reverse
    //+ sequence + score
    output << reader.displayHeader(&fasta_name) << "  " << i + 1 << "  " << "+  "
        << motif.afficheSequence() << "  " << motif.scoreMotif(&pwm) << std::endl;

    //Reverse motif reading
    motif.inverseMotif();

    //Display ex: sequence name + position on sequence + forward/reverse
    //+ sequence + score
    output << reader.displayHeader(&fasta_name) << "  " << i + 1 << "  " << "-  "
        << motif.afficheSequence() << "  " << motif.scoreMotif(&pwm) << std::endl;

  }

  output.close();
}
