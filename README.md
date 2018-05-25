**Contextualização**

O desafio desta primeira edição da Roboweek tem como motivação o uso de robôs no resgate de pessoas. O contexto do cenário envolve uma pessoa inconsciente ou incapacitada que necessita de ajuda o mais rápido possível, seja recebendo remédios ou suprimentos. O caminho até a pessoa, porém, está repleto de obstáculos. 

**Regras**

Duas equipes disputarão simultaneamente para ver quem chegará à pessoa primeiro. Os robôs partirão de pontos pré-determinados e deverão cruzar a linha de chegada em não mais que três minutos. O primeiro robô que cruzar a linha de chegada vence e, caso o tempo se esgote antes de algum dos dois conseguir, o que estiver mais próximo de chegar na pessoa vencerá.

Os robôs são equipados com um sensor laser e deverão utilizar as informações provenientes dele para desviar dos obstáculos.

Os integrantes das equipes serão escolhidos por meio de sorteio entre os participantes que demonstraram interesse em realizar o desafio.

Antes do início das provas os organizadores recolherão somente o código que as equipes editaram (roboweek/src/roboweek_node.cpp) para que se dê início à competição.

**Informações extras**

A orientação em graus do robô inicialmente segue o padrão da imagem abaixo, sendo necessário tratar os valores caso queira utilizar de 0 a 360 graus:

O laser possui 270 graus de alcance e suas leituras se dão conforme a figura abaixo. As distâncias percebidas pelo sensor são informadas de forma que cada grau é representado por uma posição no vetor de distâncias do laser.

**Instruções**

Após garantir que o ROS está instalado, que um workspace foi criado e ambos tenham sido configurados corretamente (linhas “source .../setup.bash” adicionadas no arquivo ~/.bashrc), siga os seguintes passos para iniciar:

Extraia o conteúdo do arquivo ‘desafio_roboweek_2018.zip’ na pasta “catkin_ws/src”
Verifique se há dependências faltando e instale-as com o comando:
$ rosdep install -a 
Compile o código com o comando:
$ cd ~/catkin_ws && catkin_make
Para iniciar na posição 1 execute:
$ roslaunch roboweek pos_1.launch
	Ou, para iniciar na posição 2:
		$ roslaunch roboweek pos_2.launch

Faça suas modificações no arquivo "desafio_roboweek/roboweek/src/roboweek_node.cpp", recompile o pacote (passo 3) e execute o launch novamente (passo 4).

**Problemas Frequentes**

Caso o Gazebo trave na primeira execução (tela de loading por mais de 60 segundos), encerre o roscore e tente rodar o arquivo launch novamente.

**Fontes extras**

Caso necessite revisar conceitos, instalar o ROS, criar um workspace ou ver códigos de exemplo, além da própria documentação oficial disponível em http://wiki.ros.org, outro grande recurso é a própria apresentação do minicurso de ROS, que inclui muitas informações relevantes à tarefa proposta, incluindo um zip com códigos. Isto pode ser encontrado em https://drive.google.com/drive/folders/1xdUB4yhlMCWH4obID-T9EmVmmBWHiueO
