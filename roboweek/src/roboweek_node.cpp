#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cfloat>
#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <sensor_msgs/LaserScan.h>
#include <nav_msgs/Odometry.h>
#include "std_msgs/String.h"
#include <tf/transform_datatypes.h>

//Variaveis Globais Para Leitura de Dados
nav_msgs::Odometry current_pose;
sensor_msgs::LaserScan current_laser;

//Funcao Callback do Laser
void lasercallback(const sensor_msgs::LaserScan::ConstPtr& laser)
{
	current_laser = *laser;

	return;
}

//Funcao Callback da Pose
void posecallback(const nav_msgs::Odometry::ConstPtr& pose)
{
        current_pose = *pose;

	return;
}


int main(int argc, char** argv)
{

    ros::init(argc, argv, "resgate");  // Inicializacao do Nodo

    ros::NodeHandle n; 		     

    // Configuracao do topico a ser publicado
    ros::Publisher vel_pub = n.advertise<geometry_msgs::Twist>("cmd_vel", 10); 

    // Configuracao dos topicos a serem lidos
    ros::Subscriber sub = n.subscribe("scan", 10, lasercallback);
    ros::Subscriber sub1 = n.subscribe("ground_truth", 10, posecallback);

    // Define a frequencia do no
    ros::Rate loop_rate(20);

    // Declaracoes
    geometry_msgs::Twist speed_create;  // Comando de Velocidade
    double v1=0.0, v2=0.0;              // Velocidades. v1: vel linear. v2: vel angular

    // Evita ler dados do sensor antes dele ter sido inicializado
    sleep(1); // Aguarda 1 seg antes de iniciar
    ros::spinOnce();

    //Loop Principal. Executa enquanto o roscore estiver 'ok'
    while(ros::ok()) 
    {
        // Seu codigo vai aqui
	ROS_INFO("Seu codigo esta sendo executado."); // Printa a string, similar ao printf

        // Envia Sinal de Velocidade
        speed_create.linear.x=v1;
        speed_create.angular.z=v2;
        vel_pub.publish(speed_create);
        ros::spinOnce();
        loop_rate.sleep();
    }
    return 0;
}
