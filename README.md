# Grafos
## Act 4.2 - Actividad Integral de Grafos (Evidencia Competencia CS)

Para evitar el problema que se tuvo en el Canal de Suez, la compañía naviera "International Seas, LTD." ha determinado que cada carguero tendrá un máximo número de puertos (MNP). Este número indica la cantidad de puertos en los cuáles un carguero puede atracar antes de tener que recorrer la ruta en sentido contrario. Cada vez que la nave atraca en un puerto, disminuye el MNP en 1. Si el valor de MNP llega a cero, el carguero tendrá que "girar" y recorrer su ruta en sentido inverso. Dada de una red de puertos, un puerto inicial de un carguero y un valor MNP, deberás determinar la cantidad de puertos que no van a poder ser visitados por ese carguero.

### Entrada

Cada entrada tendrá el siguiente formato. Empieza dos número enteros (n y m) que son la cantidad de puertos y cantidad de conexiones entre los puertos de la red. Después, vienen n lineas, una por cada nombre de puerto (una sola palabra) y porsteriormente vienen m lineas con m conexiones en formato de pares de nombres de puertos. Estos pares identifican los puertos que están conectados por una ruta de navegación. No habrá más que una ruta de navegación directa entre cualquier par de puertos y ninguna red contendrá más de 30 puertos. Después de la descripción de la red, habrá un número entero, NQ, que especifica el número de consultas que se realizarán. A continuación, habrá NQ líneas conteniendo el nombre del puerto de inicio y el MNP inicial.

### Salida

Para cada consulta, muestra una sola línea que indica el número de caso de prueba (numerados secuencialmente desde uno), el número de puertos a los cuales no se puede llegar, el nombre del puerto inicial y el valor inicial de MNP. A continuación encontrarás un ejemplo de entrada y salida.

### Ejemplo de entrada

13 16
Alexandria
Algeciras
Ambarli
Antwerp
Balboa
Bandar
Barcelona
Bremen
Busan
Cai_Mep
Callao
Cartagena
Charleston
Alexandria Algeciras
Algeciras Ambarli
Ambarli Antwerp
Alexandria Balboa
Balboa Bandar
Bandar Barcelona
Antwerp Bremen
Bremen Busan
Algeciras Cai_Mep
Cai_Mep Callao
Ambarli Cartagena
Barcelona Callao
Cai_Mep Cartagena
Callao Charleston
Cartagena Charleston
Charleston Busan
2
Cai_Mep 2
Cai_Mep 3

### Ejemplo de salida

Case 1: 5 ports not reachable from port Cai_Mep with MNP = 2. 
Case 2: 1 ports not reachable from port Cai_Mep with MNP = 3. 
