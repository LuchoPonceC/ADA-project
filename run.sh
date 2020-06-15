make clean
make all
clear
./main < tests > salida &
./main < tests
wait 1
python3 parser.py > resultados
rm -r salida
