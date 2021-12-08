#include <stdio.h>
#include <time.h>
struct tm* getDateTimeCurrent()
{

  struct tm *data_hora_atual;
  time_t tempoEmsegundos;
  time(&tempoEmsegundos);
  data_hora_atual = localtime(&tempoEmsegundos);

  return data_hora_atual;
}
