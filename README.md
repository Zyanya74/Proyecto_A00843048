# Proyecto_A00843048
# Simulación de Combate

```mermaid
classDiagram
    class Unidad {
        - nombre: string
        - vidaMax: int
        - vidaActual: int
        - ataque: int
        - nivel: int
        + recibirDanio(int): void
        + estaVivo(): bool
        + atacar(Unidad*): void
        + imprimir(): void
    }

    class Guerrero {
        - fuerza: int
        + imprimir(): void
    }

    class Arquero {
        - precision: float
        + imprimir(): void
    }

    class Mago {
        - mana: int
        + imprimir(): void
    }

    Unidad <|-- Guerrero
    Unidad <|-- Arquero
    Unidad <|-- Mago


