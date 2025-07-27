# Proyecto_A00843048
classDiagram
    class Unidad {
        - string nombre
        - int vida
        - int salud
        - int ataque
        - int nivel
        + Unidad()
        + Unidad(nombre, vida, ataque, nivel)
        + string getNombre()
        + int getVida()
        + int getSalud()
        + int getAtaque()
        + int getNivel()
        + void setNombre(nombre)
        + void setVida(vida)
        + void setSalud(salud)
        + void setAtaque(ataque)
        + void setNivel(nivel)
        + int porcentajeSalud()
        + void imprimeBarra()
        + virtual void imprimir()
        + virtual void recibeAtaque(int)
        + virtual void atacar(Unidad&)
    }

    class Guerrero {
        - int fuerza
        + Guerrero()
        + Guerrero(vida, ataque, nivel, fuerza)
        + int getFuerza()
        + void setFuerza(fuerza)
        + void imprimir()
        + void recibeAtaque(int)
        + void atacar(Unidad&)
    }

    class Arquero {
        - float precision
        + Arquero()
        + Arquero(vida, ataque, nivel, precision)
        + float getPrecision()
        + void setPrecision(precision)
        + void imprimir()
        + void atacar(Unidad&)
    }

    class Mago {
        - int mana
        + Mago()
        + Mago(vida, ataque, nivel, mana)
        + int getMana()
        + void setMana(mana)
        + void imprimir()
        + void recibeAtaque(int)
        + void atacar(Unidad&)
    }

    Unidad <|-- Guerrero
    Unidad <|-- Arquero
    Unidad <|-- Mago


