# Nombre del ejecutable
TARGET = combate

# Archivos fuente
SRCS = main.cpp Unidad.cpp Tipos.cpp Utilidades.cpp

# Archivos objeto (reemplaza .cpp por .o)
OBJS = $(SRCS:.cpp=.o)

# Compilador
CXX = g++

# Opciones de compilación
CXXFLAGS = -std=c++11 -Wall

# Enlace para consola (importante en MSYS2 UCRT64)


# Regla por defecto
all: $(TARGET)
	@echo "Ejecutando $(TARGET):"
	./$(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $@ 

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	del *.o *.exe 2>nul || rm -f *.o $(TARGET) # Funciona en Windows y Unix

