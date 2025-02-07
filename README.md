# Gestion_Logement

L’objectif de ce TP est d’informatiser la gestion des étudiants d’une résidence universitaire.
Vous allez implémenter un programme qui va permettre à un administrateur enregistré
dans l’application de :

1. Se connecter au programme en utilisant un mot de passe
2. Ajouter un étudiant à une position donnée s’il y en encore des places disponibles
3. Afficher un étudiant donné suivant un critère ou tous les étudiants
4. Modifier un étudiant donné
5. Supprimer un étudiant donné.
6. Exporter la liste de tous les étudiants dans un fichier texte
7. Produire les fiches d’étudiants
8. Ajouter une chambre ou supprimer une chambre
9. Afficher tous les chambres disponibles et leurs types
10. Afficher tous les chambres occupées et les occupants
11. Modifier les informations d’une chambre
12. Charger une liste d’étudiants préenregistrés dans un fichier texte
13. Charger une liste de logement préenregistrés dans un fichier texte
14. Afficher les étudiants qui sont sur la liste d’attente si jamais il y en a
15. Ajouter/Supprimer/Modifier un enseignant (utilisateur)
    Pour ce, un étudiant possède les informations suivantes :
    a. L’identifiant de l'étudiant _ (5 caractères) _
    b. Le prénom _
    c. Le nom _
    d. La date de naissance _
    e. Le lieu d'étude _
    f. L’échelon pour la bourse _ (0 à 7) _
    g. Le lieu préférentiel choisi _ (A ou B ou C) _
    h. L’état de santé _ (0 si normal | 1 si handicap) _
    i. Le logement préférentiel choisi. _ (0 si chambre | 1 si studio | 2 si T1 | 3 si T2 )
    Dans la même optique de gestion, un étudiant qui demande un logement, devra être
    enregistré avec les informations sur sa demande. Le système devra être à mesure
    d’informer à l’utilisateur si la chambre demandée est disponible. Si oui, la chambre est
    accordée à l’étudiant et sinon il est mis sur la liste d’attente.La demande sera représentée par les informations suivantes :
    a. Un identifiant de l'étudiant _
    b. Le logement attribué
    c. La demande de changement _ ( 0 si normal | 1 si demande en attente )
    Pour un logement, on enregistrera les informations suivantes :
    a. L’identifiant de la chambre _ (4 caractères) _
    b. Le bâtiment _
    c. L'étage
    d. Le numéro de la chambre
    e. Le type du logement _ (0 si chambre | 1 si studio | 2 si T1 |3 si T2) _
    f. La disponibilité _ (0 si disponible | 1 si occupé | 2 si en travaux | 3 si pour
    handicap) _/
    La résidence universitaire (la cité) est représentée par les informations suivantes :
    a. L’identifiant du bâtiment _(A ou B ou C) _
    b. Le nombre maximum de logement _
    c. Le nombre de logement disponible restant _
    d. Le nom du bâtiment _
    e. L’adresse du bâtiment _
    f. Le code postal du bâtiment \*/
    Les structures de données :
     On créera les structures (struct) suivantes :
     Etudiant : qui servira de construire la liste chaînée d’étudiants
     Logement : qui servira de construire la liste chaînée de logements qui constitue la
     Bloc : qui contient un groupe de logements
     Un fichier qui contiendra les informations de la cité dont le nombre de blocs qui la
    constituent
     Pour la suite du projet, vous utiliserez les structures de données qui vous semblent bon
    et adéquates.
