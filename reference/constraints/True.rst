True
====

Valide qu'une valeur est ``vraie`` (true). Sp�cifiquement, cette contrainte
v�rifie que la valeur est exactement ``true``, exactement l'entier ``1``, ou exactement
la chaine de caract�re � ``1`` �.

Lisez �galement :doc:`False <False>`.

+----------------+---------------------------------------------------------------------+
| S'applique �   | :ref:`propri�t� ou m�thode<validation-property-target>`             |
+----------------+---------------------------------------------------------------------+
| Options        | - `message`_                                                        |
+----------------+---------------------------------------------------------------------+
| Classe         | :class:`Symfony\\Component\\Validator\\Constraints\\True`           |
+----------------+---------------------------------------------------------------------+
| Validateur     | :class:`Symfony\\Component\\Validator\\Constraints\\TrueValidator`  |
+----------------+---------------------------------------------------------------------+

Utilisation de base
-------------------

Cette contrainte peut �tre appliqu�e � une propri�t� (ex une propri�t� ``termsAccepted``
d'un formulaire d'inscription) ou une m�thode � getter �. Elle est plus puissante dans le
second cas, o� vous pouvez v�rifier que la m�thode retourne true. Par exemple, supposons
que vous avez la m�thode suivante :

.. code-block:: php

    // src/Acme/BlogBundle/Entity/Author.php
    namespace Acme\BlogBundle\Entity;

    class Author
    {
        protected $token;

        public function isTokenValid()
        {
            return $this->token == $this->generateToken();
        }
    }

Vous pouvez appliquer la contrainte ``True`` � cette m�thode.

.. configuration-block::

    .. code-block:: yaml

        # src/Acme/BlogBundle/Resources/config/validation.yml
        Acme\BlogBundle\Entity\Author:
            getters:
                tokenValid:
                    - "True": { message: "Le token est invalide" }

    .. code-block:: php-annotations

        // src/Acme/BlogBundle/Entity/Author.php
        use Symfony\Component\Validator\Constraints as Assert;

        class Author
        {
            protected $token;

            /**
             * @Assert\True(message = "Le token est invalide")
             */
            public function isTokenValid()
            {
                return $this->token == $this->generateToken();
            }
        }

    .. code-block:: xml

        <?xml version="1.0" encoding="UTF-8" ?>
        <!-- src/Acme/Blogbundle/Resources/config/validation.xml -->

        <constraint-mapping xmlns="http://symfony.com/schema/dic/constraint-mapping"
            xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
            xsi:schemaLocation="http://symfony.com/schema/dic/constraint-mapping http://symfony.com/schema/dic/constraint-mapping/constraint-mapping-1.0.xsd">

            <class name="Acme\BlogBundle\Entity\Author">
                <getter property="tokenValid">
                    <constraint name="True">
                        <option name="message">Le token est invalide</option>
                    </constraint>
                </getter>
            </class>
        </constraint-mapping>

    .. code-block:: php

        // src/Acme/BlogBundle/Entity/Author.php
        use Symfony\Component\Validator\Mapping\ClassMetadata;
        use Symfony\Component\Validator\Constraints\True;
        
        class Author
        {
            protected $token;
            
            public static function loadValidatorMetadata(ClassMetadata $metadata)
            {
                $metadata->addGetterConstraint('tokenValid', new True(array(
                    'message' => 'Le token est invalide',
                )));
            }

            public function isTokenValid()
            {
                return $this->token == $this->generateToken();
            }
        }

Si la m�thode ``isTokenValid()`` retourne false, la validation �chouera.

Options
-------

message
~~~~~~~

**type**: ``string`` **default**: ``This value should be true``

Le message qui sera affich� si la donn�e ne vaut pas true.
