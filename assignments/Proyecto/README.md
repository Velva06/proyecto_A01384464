Diagrama UML:

+-----------------------------+

|          Unidad             |

+-----------------------------+

| - vida: int                |

| - salud: int               |

| - ataque: int              |

| - nivel: int               |

+-----------------------------+

| + Unidad()                 |

| + Unidad(vida, ataque, nivel) |

| + getVida(): int           |

| + getSalud(): int          |

| + getAtaque(): int         |

| + getNivel(): int          |

| + setVida(v: int): void    |

| + setSalud(s: int): void   |

| + setAtaque(a: int): void  |

| + setNivel(n: int): void   |

| + calcularPorcentajeSalud(): int |

| + mostrarBarraVida(): void |

| + recibeAtaque(p: int): void     |

| + atacar(obj: Unidad&): void     |

| + imprimir(): void         |

+-----------------------------+

