#!/bin/bash

# Variable GITHUB_USER
GITHUB_USER="AlexMagno2003"

# Consultar la URL
response=$(curl -s "https://api.github.com/users/${GITHUB_USER}")

# Obtener los valores del JSON
github_user=$(echo $response | jq -r '.login')
user_id=$(echo $response | jq -r '.id')
created_at=$(echo $response | jq -r '.created_at')

# Imprimir el mensaje
mensaje="Hola ${github_user}. User ID: ${user_id}. Cuenta fue creada el: ${created_at}."
echo $mensaje

fecha=$(date +%Y-%m-%d)
log_directory="/tmp/${fecha}"
mkdir -p $log_directory

log_file_path="${log_directory}/saludos.log"
echo $mensaje >> $log_file_path