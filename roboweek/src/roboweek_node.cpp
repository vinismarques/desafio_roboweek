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
sensor_msgs::LaserScan current_laser;
geometry_msgs::Quaternion orientacao;
geometry_msgs::Point posicao;

bool laserPronto = false,
     posePronto = false;

//Funcao Callback do Laser
void lasercallback(const sensor_msgs::LaserScan::ConstPtr& laser)
{
	current_laser = *laser;
    laserPronto = true;

    return;
}

//Funcao Callback da Pose
void posecallback(const nav_msgs::Odometry::ConstPtr& pose)
{

    posicao = pose->pose.pose.position; // Posicao em x y z
    orientacao = pose->pose.pose.orientation; // Orientacao em z
    posePronto = true;

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

    // Define a frequencia do loop
    ros::Rate loop_rate(20);

    // Declaracoes
    double v1=0.0, v2=0.0;  // Velocidades v1=linear v2=angular
    double oriRad, oriGraus; // Orientacao em radianos e em graus

    // Aguarda a primeira mensagem de cada sensor para evitar erros
    while (ros::ok() && !laserPronto && !posePronto)
    {
        ros::spinOnce();
        loop_rate.sleep();
    }

    //Loop Principal. Executa enquanto o roscore estiver 'ok'
    while(ros::ok()) 
    {
        // Calcula orientacao tanto em graus quanto radianos
        oriRad = tf::getYaw(orientacao);
        oriGraus = oriRad * 180.0 / M_PI;

        /* SEU CODIGO VAI AQUI */
        ROS_INFO("Seu codigo esta sendo executado."); // Printa a string, similar ao printf
        ROS_INFO("rad=%lg graus=%lg", oriRad, oriGraus); 



        // Envia Sinal de Velocidade
        geometry_msgs::Twist vel;

        vel.linear.x=v1;
        vel.angular.z=v2;
        vel_pub.publish(vel);
        ros::spinOnce();
        loop_rate.sleep();
    }
    return 0;
}
