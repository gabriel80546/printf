source ../refazer.sh; cd repo; make run; cd ..
source ../refazer.sh; rm -rf printfcopia; cp -rvn ../printfcopia . ; cp -rvn repo printfcopia; cd printfcopia/repo; bash runtest.sh; cd ../..
rm -rf ../printf; git clone https://github.com/gabriel80546/printf ../printf; source ../refazer.sh; cd repo; make run; cd ..
rm -rf ../printf; git clone https://github.com/gabriel80546/printf ../printf; source ../refazer.sh; rm -rf printfcopia; cp -rvn ../printfcopia . ; cp -rvn repo printfcopia; cd printfcopia/repo; bash runtest.sh; cd ../..
