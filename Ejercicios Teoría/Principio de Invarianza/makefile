
#Definimos etiquetas
DOC=doc
SRC=src
OUTPUTFOLDER=output
CPPNAME=BurbujaC
JAVANAME=BurbujaJava
CPPOUTPUT=cpp.out
JAVAOUTPUT=java.out

#Compilar el archivo C++
all : ejecutar

cpp :
	g++ -o $(SRC)/$(CPPNAME) $(SRC)/$(CPPNAME).cpp

#Compilar el archivo Java

java : 
	javac $(SRC)/$(JAVANAME).java

#Ejecutamos cada uno y guardamos en la salida

ejecutar : cpp java
		cd $(SRC);./$(CPPNAME) > ../$(OUTPUTFOLDER)/$(CPPOUTPUT)
		cd $(SRC);java $(JAVANAME) > ../$(OUTPUTFOLDER)/$(JAVAOUTPUT)
#LaTEX

memoria : 
	pdflatex -shell-escape -synctex=1 -interaction=nonstopmode $(DOC)/memoria.tex 

#Limpiar

clean :
	rm -f $(SRC)/$(CPPNAME) $(SRC)/$(JAVANAME) 

mrproper : clean
	rm -f $(OUTPUTFOLDER)/*