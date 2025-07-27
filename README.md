# Proyecto_A00843048
# Unidades de Combate

Simulación de combate con unidades tipo `Unidad`, `Hechicero` y `Arquero`.

## UML (Mermaid)

```mermaid
classDiagram
    class Unidad {
        - int vida
        - int salud
        - int ataque
        - int nivel
        + int porcentajeSalud()
        + void imprimeBarra()
        + void recibeAtaque(int)
        + void atacar(Unidad&)
        + void imprimir()
    }

    class Hechicero {
        - int mana
        + void lanzarHechizo(Unidad&)
        + void imprimir()
    }

    class Arquero {
        - int flechas
        + void disparar(Unidad&)
        + void imprimir()
    }

    Hechicero --|> Unidad
    Arquero --|> Unidad

