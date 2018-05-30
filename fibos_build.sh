cd eos

sed "s/\.git/docs/g;" eosio_build.sh | sh
# sed "s/\.git/docs/g;s/=Release/=Debug/g" eosio_build.sh | sh

cd ..
cd fibjs
sh build -j
