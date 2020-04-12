for i in *
do
    echo $i
    read pre
    if [ $pre ];then
        git mv "$i" "${pre}.${i}"
    fi
done