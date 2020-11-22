#include<stdio.h>
#include "../objects.h"
#include "../file.h"

void main()
{

    char admin_file[] = "../data/admin_list.txt";
    

    Admin admin_list[6] = {{"omkar_sahu", "18ms007"},
						{"disha_baidya", "18ms078"},
						{"amarjeet_kumar", "18ms131"},
						{"alice_chabbra", "18ms132"},
						{"aesha_lahiri", "18ms149"},
						{"tahiti_dutta", "18ms165"}};
    						


    writeFile(admin_file, &admin_list, sizeof(Admin), 6);

}
