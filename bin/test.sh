#!/bin/bash

# --- CONFIGURATION ---
PUSH_SWAP="./push_swap"
# Modifie cette ligne selon ton OS ou si tu as ton propre checker
CHECKER="./checker_linux" 

# --- COULEURS ---
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

# --- VERIFICATION PRÉLIMINAIRE ---
if [ ! -f "$PUSH_SWAP" ]; then
    echo -e "${YELLOW}Compilation du projet...${NC}"
    make
    if [ ! -f "$PUSH_SWAP" ]; then
        echo -e "${RED}Erreur : L'exécutable push_swap est introuvable.${NC}"
        exit 1
    fi
fi

if [ ! -f "$CHECKER" ]; then
    echo -e "${YELLOW}Attention : Checker introuvable ($CHECKER).${NC}"
    echo -e "Le script vérifiera le nombre de coups, mais pas si la liste est réellement triée."
    CHECKER_CMD="true"
else
    CHECKER_CMD="$CHECKER"
fi

echo -e "${BLUE}========================================${NC}"
echo -e "${BLUE}       PUSH_SWAP ULTIMATE TESTER        ${NC}"
echo -e "${BLUE}========================================${NC}"

# --- FONCTION D'ERREUR ---
check_error()
{
    TEST_NAME="$1"
    ARG="$2"
    echo -n "Test $TEST_NAME : "
    OUTPUT=$($PUSH_SWAP $ARG 2>&1)
    
    if [[ "$OUTPUT" == "Error" ]]; then
        echo -e "${GREEN}[OK]${NC} (A bien affiché Error)"
    else
        echo -e "${RED}[KO]${NC} (Attendu: Error, Reçu: '$OUTPUT')"
        echo -e "   Args: $ARG"
    fi
}

# --- TESTS DE PARSING ---
echo -e "\n${YELLOW}--- 1. TESTS DE PARSING (ERREURS) ---${NC}"
check_error "Non-numérique" "1 2 a 4"
check_error "Doublons" "1 2 3 2 5"
check_error "MAX_INT + 1" "2147483648 1 2"
check_error "MIN_INT - 1" "-2147483649 1 2"
check_error "Nombre collé" "1 2 3-5"

# --- TEST IDENTITE ---
echo -e "\n${YELLOW}--- 2. TEST LISTE DÉJÀ TRIÉE ---${NC}"
ARG="1 2 3 4 5"
MOVES=$($PUSH_SWAP $ARG | wc -l)
echo -n "Test Déjà Trié : "
if [ "$MOVES" -eq 0 ]; then
    echo -e "${GREEN}[OK]${NC} (0 instructions)"
else
    echo -e "${RED}[KO]${NC} ($MOVES instructions au lieu de 0)"
fi

# --- FONCTION DE PERFORMANCE ---
test_perf()
{
    COUNT=$1
    LIMIT=$2
    ITERATIONS=$3
    TOTAL_MOVES=0
    MAX_MOVES=0
    MIN_MOVES=100000

    echo -e "\n${YELLOW}--- 3. TEST PERFORMANCE ($COUNT nombres, $ITERATIONS essais) ---${NC}"
    echo -e "Objectif : < $LIMIT coups"

    for ((i=1; i<=ITERATIONS; i++))
    do
        # Génération de nombres aléatoires via Ruby (standard à 42)
        ARG=$(ruby -e "puts (1..$COUNT).to_a.shuffle.join(' ')")
        
        # Exécution
        MOVES=$($PUSH_SWAP $ARG | wc -l)
        MOVES=$(echo $MOVES | tr -d ' ') # Trim spaces
        
        # Vérification du tri avec le checker
        if [ "$CHECKER_CMD" != "true" ]; then
            CHECK_RES=$($PUSH_SWAP $ARG | $CHECKER_CMD $ARG)
        else
            CHECK_RES="OK" # Bypass si pas de checker
        fi

        # Mise à jour stats
        TOTAL_MOVES=$((TOTAL_MOVES + MOVES))
        if (( MOVES > MAX_MOVES )); then MAX_MOVES=$MOVES; fi
        if (( MOVES < MIN_MOVES )); then MIN_MOVES=$MOVES; fi

        # Affichage barre de progression simplifiée
        if [ "$CHECK_RES" == "OK" ]; then
            if (( MOVES <= LIMIT )); then
                echo -ne "${GREEN}.${NC}"
            else
                echo -ne "${RED}X${NC}"
            fi
        else
            echo -ne "${RED}F${NC}" # Fail tri
        fi
    done

    AVG=$((TOTAL_MOVES / ITERATIONS))
    echo -e "\n\nRésultats pour $COUNT éléments :"
    echo -e "Moyenne : ${BLUE}$AVG${NC}"
    echo -e "Max     : $MAX_MOVES"
    echo -e "Min     : $MIN_MOVES"

    if (( AVG <= LIMIT && MAX_MOVES <= LIMIT )); then
        echo -e "Status  : ${GREEN}EXCELLENT${NC}"
    elif (( AVG <= LIMIT )); then
         echo -e "Status  : ${YELLOW}BON (Attention au Max)${NC}"
    else
         echo -e "Status  : ${RED}DANGER (Optimisation requise)${NC}"
    fi
}

# --- LANCEMENT DES TESTS DE PERF ---

# Test 3 nombres (Max 3)
test_perf 3 3 10

# Test 5 nombres (Max 12)
test_perf 5 12 10

# Test 100 nombres (Objectif < 700 pour 5/5 points)
test_perf 100 700 20

# Test 500 nombres (Objectif < 5500 pour 5/5 points)
test_perf 500 5500 20

echo -e "\n${BLUE}=== FIN DES TESTS ===${NC}"
