#entrée 1 chaine de 12 entier
#Xa Ya Za Xb Yb Zb Xc Yc Zc RSSIa RSSIb RSSIc id trame

name=$(echo ${13}_$(date '+%d-%m-%Y').txt)
echo ${14} $(date --utc '+%H:%M:%S') $(./calculator ${1} ${2} ${3} ${4} ${5} ${6} ${7} ${8} ${9} ${10} ${11} ${12})>> ${name}
#sortie dans un fichier 
#$id_$date.txt
