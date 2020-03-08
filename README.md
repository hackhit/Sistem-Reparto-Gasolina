# LuciaTrabajo
El trabajo que Lucia me pidio

## Estructura y funcionamiento del proyecto
>### Objetos involucrados a tomar en cuenta
  >- Central de monitoreo la cual manejara toda la informacion
  >- Distribuidora de gasolina (No tomo en cuenta si es la refineria o otra cosa ya que no importa)
  >- Gandola de gasolina(cambiar el nombre) con sus choferes para monitorearlos
  >- Gasolinera (Estacion de gasolina) con el encargado de monitorear (si, para monitorearlo)
  >- Carro¿? solo se necesita sus placa no se le aplicara ninguna funcion a el solo sera dato de entrada ya que lo que nos interesa es que solo se le heche gasolina al carro una vez, no quien la lleno
  
>### Datos a utilizar
  >- Gasolina 
  >- Placa de la gandola
  >- Informacion basica del chofer
  >>- Nombre
  >>- Cedula
  >>- Telefono
  >- Informacion basica del encargado
  >>- Nombre
  >>- Cedula
  >>- Telefono
  >- placa del carro al cual se le surtio gasolina
  
>## Funciones de cada elemento 
> De menor prioridad a la mayor
  >### Personas
  >>>- nombre
  >>>- cedula
  >>>- telefono
  >>#### Obtener informacion
  
  >### Gasolina
  >>>- litros
  >>#### Acciones
  >>>- Aumentar(litros)
  >>>- Dismininuir(litros)
  >>>- Cantidad actual(litros)
  
  >### Distribuidor y/o refineria
  >>>- id del distribuidor y/o refineria
  >>>- Gasolina litros
  >>### Gasolina
  >>- Producir y/o recibir (litros)
  >>- Entregar(litros)
  
  >### Gandola de gasolina
  >>>- placa
  >>>- Persona chofer
  >>>- gasolina litros
  >>#### Gasolina
  >>>- Extraer(litros, hora)
  >>>- Recibir(litros, hora)
  
  >### Gasolinera
  >>>- id de la gasolinera
  >>>- gasolina litros
  >>>- Persona encargado
  >>>- listadecarros
  >>>- lista de gandolas
  >>#### Informacion del encargado
  >>>- Dar informacion (cedula, nombre, telefono)
  >>>- Obtener informacion (cedula, nombre, telefono)
  >>#### Gasolina
  >>>- Extraida (Placa del carro, litros extraidos, hora¿?)
  >>>- Recibir (Placa de la gandola, litros entregados, hora¿?)
  >>>- Calculos¿?(No se si sea necesario)
  >>#### Terminar turno del encargado()
  >>>- enviar informacion a la central (litros vendidos, litros remanentes, lista de carros, gandolas, litros entregados por la gandola)
  
  ># CENTRAL
  >>>- lista de refinerias
  >>>- lista de gasolineras 
  >>>- lista de gandolas
  >>### Inicializar central
  >>>- Recibir datos de refinerias
  >>>- Recibir datos de gasolineras
  >>>- Recibir datos de gandolas
  >>### Chequeo al finalizar el dia
  >>>- Analizar informacion de venta de gasolina confirmando a donde llego y se movio la gasolina para ver si concuerda con la base de datos del dia para revisar si hubo o no robo de gasolina (sii tengo que desarrollar esto pero lo hare cuando me ponga a pensar como hacer los calculos)
