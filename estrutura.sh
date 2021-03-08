# git clone https://github.com/mrjvs/42cursus_gnl_tests
caminho=$(pwd)
mkdir testeum
mkdir testedois
mkdir testetreis
git clone https://github.com/cacharle/ft_printf_test  testeum/repo
git clone https://github.com/Mazoise/42TESTERS-PRINTF testedois/repo
git clone https://github.com/cclaude42/PFT_2019       testetreis/repo

cp -r -v -n testeum/repo    testeum/copia
cp -r -v -n testedois/repo  testedois/copia
cp -r -v -n testetreis/repo testetreis/copia
#echo $caminho
caminho=$(echo $caminho | sed 's/\//\\\//g')
#echo $caminho
cp printf/refazer.sh .
cat refazer.sh | sed "s/fWU3KdermTW3n9FRbtXwZ7AM/$caminho/g" > temp; mv temp refazer.sh
