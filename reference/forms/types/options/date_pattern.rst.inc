pattern
~~~~~~~

**type**: ``string``

Cette option n'est utile que si l'option `widget`_ est d�finie � ``choice``.
Le masque par d�faut se base sur l'option `format`_, est essaye de trouver
les caract�res ``M``, ``d``, et ``y`` du format. Si aucune occurence n'est
trouv�e, la valeur par d�faut est la chaine de caract�res ``{{ year }}-{{ month }}-{{ day }}``.
Les identifiants de cette option sont :

  * ``{{ year }}``: Remplac� par le widget ``year``
  * ``{{ month }}``: Remplac� par le widget ``month``
  * ``{{ day }}``: Remplac� par le widget ``day``