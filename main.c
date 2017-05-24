#include "config.h"
#include "input.h"
#include "output.h"
#include "date.h"
#include <stdlib.h>

/*********************Prototipos*********************/
status_t    validate_args(int argc, char *argv[], *config_t);
/****************************************************/

int main(int argc, char * argv[]){
    status_t st;
    time_t machine_time;
    struct tm temp;
    char gps_time[MAX];

    if(st=(validate_args(argc,argv, &config)) != OK){
        show_error_message(st);
        return EXIT_FAILURE;
    } 
    if (time(&machine_time) == -1){	/* Se compara con -1 porque así está definido en el estándar ANSI C '89 */
        print_error_message(ERROR_TIME);
        return EXIT_FAILURE;
    }   
    temp = localtime(&machine_time);
    while ((st = parse_line(gps_time)) =! EOF)
    { 
        if (st == READ_ERROR)
            show_error_message(st_parse);
        if (st == FOUND)
        {
            parse_time (temp, gps_time);
            switch(format)
            {
                case FORMAT_TYPE1:
                    show_formatted_time_type1(temp);
                    break;

                case FORMAT_TYPE2:
                   show_formatted_time_type2(temp);
                   break;
         
                default:
                ;
            }
    }
    printf("%s\n",MSG_PROGRAM_END);
    return EXIT_SUCCESS;
}
/*recordar validar pasaje de */
/*punteros                   */


