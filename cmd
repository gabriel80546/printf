source ../refazer.sh; cd repo; make run; cd ..
source ../refazer.sh; rm -rf printfcopia; cp -rvn ../printfcopia . ; cp -rvn repo printfcopia; cd printfcopia/repo; bash runtest.sh; cd ../..
