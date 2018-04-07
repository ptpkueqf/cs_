#include "ClientSocket.h"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <pthread.h>
#include <string.h>
using namespace std;
class Client
{
  public:
    struct thread_data
    {
        int thread_id;
        char *message;
    };

    //void *PrintHello(void *threadarg);
    static void *PrintHello(void *threadarg)
    {
        struct thread_data *my_data;
        my_data = (struct thread_data *)threadarg;
        string host(my_data->message);
        //cout<<host;
        //std::cout << "Thread ID : " << my_data->thread_id;
        //std::cout << " Message : " << my_data->message << endl;
        //if (my_data->message != "NULL")
        // ClientSocket client_socket(host, 30000);

        ClientSocket client_socket(host, 10020);

        std::string reply;

        client_socket << "Fucking cunt";
        client_socket >> reply;

        //client_socket << my_data->message;

        pthread_exit(NULL);
    }
    //void grep();
    void grep()
    {
        //int rc;
        string line;
        // string ip1,ip2;
        //ip1="128.2.2.3";
        //ip2="129.2.3.43";
        vector<string> hst;
        ifstream myfile("hosts.txt");
        if (myfile.is_open())
        {
            while (!myfile.eof())
            {
                getline(myfile, line, '\n');
                if (line.length() == 0)
                    continue;
                hst.push_back(line);
            }
            myfile.close();
        }
        //   for(int i=0;i<2;i++)
        //  cout<<hst[i];
        pthread_t threads[2];
        int rc;
        struct thread_data td[2];
        //td[1].thread_id = 1;
        //td[1].message = (char *)ip1.c_str();;
        // cout<<td[1].message;
        //td[2].thread_id = 2;
        //td[2].message = (char *)ip2.c_str();
        // cout<<td[2].message;
        for (int i = 0; i < 2; i++)
        {
            td[i].thread_id = i;
            td[i].message = (char *)hst[i].c_str();
            //cout << "\n HHH:" << td[i].message << endl;
            rc = pthread_create(&threads[i], NULL, PrintHello, (void *)&td[i]);
            if (rc)
            {
                printf("ERROR; return code from pthread_create() is %d\n", rc);
                exit(-1);
            }
        }
        /*main */
        pthread_exit(NULL);
    }
};