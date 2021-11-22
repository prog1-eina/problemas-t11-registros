# Problemas con registros (tema 11)

Soluciones a los [problemas con registros](https://miguel-latre.github.io/transparencias/pbs-tema-11-registros.pdf) de la asignatura [Programación 1](https://github.com/prog1-eina) ([Grado en Ingeniería Informática](https://webdiis.unizar.es/~silarri/coordinadorGrado/), [Escuela de Ingeniería y Arquitectura](https://eina.unizar.es/), [Universidad de Zaragoza](https://www.unizar.es/)).

Se recomienda **no consultar** estas soluciones hasta **después** de haber intentado resolverlos o haber asistido a la clase de problemas correspondiente.

## Compilación y ejecución

El código está estructurado en dos directorios (`permisos-conducir` y
`racionales`), aunque las reglas de compilación están en un único fichero
`Makefile`.

**El programa `racionales` necesita del módulo `calculos` de la práctica 3** para
reutilizar las funciones ``mcd`` y ``mcm``. El fichero `Makefile` ha sido escrito
considerando que dicho módulo se encuentra en un directorio denominado
`src/calculadora` dentro de un directorio `practica3` ubicado en la misma
carpeta que el directorio correspondiente a estas soluciones
(`problemas-t11-registros`). La ruta a este módulo puede modificarse en el
propio fichero `Makefile` si fuese preciso.

Los comentarios de encabezado de los ficheros ``racionales/racional-main.cpp`` y ``permisos-conducir/permiso-main.cpp`` contienen instrucciones para la compilación y ejecución de cada uno de ellos.
