# Gestión de Usuarios, Grupos y Permisos en Linux Mint

## Parte 1: Gestión de Usuarios

### 1. Creación de Usuarios

Para crear los tres usuarios `usuario1`, `usuario2` y `usuario3`, utilizamos el comando `useradd`.

```bash
sudo useradd -m usuario1
sudo useradd -m usuario2
sudo useradd -m usuario3
```

### 2. Asignación de Contraseñas

Establecemos contraseñas para cada usuario utilizando el comando `passwd`.

```bash
echo "usuario1:alexpswd1" | sudo chpasswd
echo "usuario2:alexpswd2" | sudo chpasswd
echo "usuario3:alexpswd3" | sudo chpasswd
```

### 3. Información de Usuarios

Mostramos la información de `usuario1` utilizando el comando `id`.

```bash
id usuario1
```

### 4. Eliminación de Usuarios

Eliminamos `usuario3` pero conservamos su directorio home utilizando el comando `userdel`.

```bash
sudo userdel usuario3
```

---

## Parte 2: Gestión de Grupos

### 1. Creación de Grupos

Creamos dos grupos llamados `grupo1` y `grupo2` utilizando el comando `groupadd`.

```bash
sudo groupadd grupo1
sudo groupadd grupo2
```

### 2. Agregar Usuarios a Grupos

Agregamos `usuario1` a `grupo1` y `usuario2` a `grupo2` utilizando el comando `usermod`.

```bash
sudo usermod -aG grupo1 usuario1
sudo usermod -aG grupo2 usuario2
```

### 3. Verificar Membresía

Verificamos que los usuarios han sido agregados a los grupos utilizando el comando `groups`.

```bash
groups usuario1
groups usuario2
```

### 4. Eliminar Grupo

Eliminamos `grupo2` utilizando el comando `groupdel`.

```bash
sudo groupdel grupo2
```

---

## Parte 3: Gestión de Permisos

### 1. Creación de Archivos y Directorios

Como `usuario1`, crea un archivo llamado `archivo1.txt` en su directorio principal y escribe algo en él.
Iniciamos sesión como `usuario1` y creamos `archivo1.txt`.

```bash
sudo -u usuario1 bash
echo "Este es el archivo1.txt" > ~/archivo1.txt
```

Crea un directorio llamado `directorio1` y dentro de ese directorio, un archivo llamado `archivo2.txt`.

```bash
mkdir ~/directorio1
echo "Este es el archivo2.txt" > ~/directorio1/archivo2.txt
```

### 2. Verificar Permisos

Verificamos los permisos del archivo y directorio usando el comando `ls -l` y `ls -ld`.

```bash
ls -l ~/archivo1.txt
ls -ld ~/directorio1
```

### 3. Modificar Permisos usando chmod con Modo Numérico

Cambiamos los permisos del `archivo1.txt` para que sólo `usuario1` pueda leer y escribir, el grupo pueda leer, y nadie más pueda hacer nada.

```bash
chmod 640 ~/archivo1.txt
```

### 4. Modificar Permisos usando chmod con Modo Simbólico

Agregamos permiso de ejecución al propietario del `archivo2.txt`.

```bash
chmod u+x ~/directorio1/archivo2.txt
```

### 5. Cambiar el Grupo Propietario

Cambiamos el grupo propietario de `archivo2.txt` a `grupo1` utilizando el comando `chown`.

```bash
sudo chown :grupo1 ~/directorio1/archivo2.txt
```

### 6. Configurar Permisos de Directorio

Cambiamos los permisos del `directorio1` para que sólo el propietario pueda entrar, el grupo pueda listar contenidos pero no entrar, y otros no puedan hacer nada.

```bash
chmod 740 ~/directorio1
```

### 7. Comprobación de Acceso

Intentamos acceder al `archivo1.txt` y `directorio1/archivo2.txt` como `usuario2` para notar cómo el permiso de directorio afecta el acceso a los archivos dentro de él.

```bash
sudo -u usuario2 bash
cat /home/usuario1/archivo1.txt
cat /home/usuario1/directorio1/archivo2.txt
```

### 8. Verificación Final

Verificamos los permisos y propietario de los archivos y directorio nuevamente con `ls -l` y `ls -ld`.

```bash
ls -l ~/archivo1.txt
ls -l ~/directorio1/archivo2.txt
ls -ld ~/directorio1
```

---

## ¿Por qué es importante gestionar correctamente los usuarios y permisos en un sistema operativo?

Gestionar correctamente los usuarios y permisos en un sistema operativo es esencial porque proporciona una capa fundamental de seguridad y control sobre los recursos del sistema. Limitar el acceso a archivos y directorios previene accesos no autorizados y protege la información sensible, garantizando que sólo las personas adecuadas puedan ver y modificar ciertos datos.

---

## ¿Qué otros comandos o técnicas conocen para gestionar permisos en Linux?

En Linux, además de los comandos básicos como chmod, chown y chgrp, existen otras herramientas y técnicas avanzadas para gestionar permisos. Una de estas herramientas son las ACLs (Access Control Lists), que permiten un control de permisos más granular que los permisos tradicionales, definiendo permisos específicos para usuarios y grupos adicionales de manera muy detallada. Además, SELinux (Security-Enhanced Linux) es una política de seguridad que proporciona un control de acceso más estricto y detallado, siendo especialmente útil para proteger sistemas en entornos críticos al implementar políticas de seguridad obligatorias. AppArmor es otra herramienta que permite definir qué recursos puede acceder un programa en el sistema, añadiendo una capa adicional de control de acceso para aplicaciones específicas.
