#create database GYM_MANAGEMENT;
use GYM_MANAGEMENT;

create table if not exists Rol(
	id_rol int auto_increment primary key,
    rol_descricion varchar(20) ,
    unique(rol_descricion)
);


create table if not exists Persona(
	cod_persona varchar(12) primary key,
    nombre varchar(20),
    apellido varchar(30),
    fecha_registro date,
    id_rol int, 
    foreign key(id_rol) references Rol(id_rol)
);



create table if not exists Paquete(
	id_paq int auto_increment primary key,
    paq_descripcion varchar(200) not null,
    paq_price decimal(5,2) not null
);



create table if not exists CabeceraFactura(
	id_cab_fact int auto_increment primary key,
    fecha_cab_fact date,
    total_cab_fact decimal(5,2),
    cod_persona varchar(12),
    foreign key(cod_persona) references Persona(cod_persona)
);


create table if not exists Usuario(
	id_usuario varchar(10) primary key,
	usuario varchar(30) not null,
    clave varchar(100) not null,
    id_rol int, 
    foreign key(id_rol) references Rol(id_rol),
    unique(usuario)
);

create table if not exists DetalleFactura(
	id_deta_fact int auto_increment primary key,
    total_deta_fact decimal(5,2),
    id_cab_fact int,
    id_paq int, 
    cantidad_paq int,
    foreign key(id_cab_fact) references CabeceraFactura(id_cab_fact),
    foreign key(id_paq) references Paquete(id_paq) 
);


select * from Rol;
select * from Persona;
select * from Paquete;
select * from CabeceraFactura;
select * from DetalleFactura;
select * from Usuario;




-- el valor de total deta será igual a id_paq * cantidad_paq, eso se calcula en el app c++
insert into DetalleFactura(total_deta_fact, id_cab_fact, id_paq, cantidad_paq)
 values( 70.0, 1, 1, 2);
 
insert into DetalleFactura(total_deta_fact, id_cab_fact, id_paq, cantidad_paq)
 values( 3.0, 1, 2, 1);
 
call update_cabecera_factura(1);
 
 

delimiter //
create procedure update_cabecera_factura( in current_cabecera int)
begin
	declare total int default 0;
	select sum( total_deta_fact )
	from DetalleFactura
	where DetalleFactura.id_cab_fact = current_cabecera
	into total;
	update CabeceraFactura set total_cab_fact = total where  CabeceraFactura.id_cab_fact = current_cabecera;
end //
delimiter ;


/*
insert into Rol(rol_descricion)
values ('Cliente'),('Administrador'),('Entrenador'),('Nutricionista'),('Fisioterapeuta');

insert into Persona(cod_persona, nombre, apellido, fecha_registro, id_rol)
values( LEFT(uuid(),7), 'Jose', 'Pinos', '2024-04-25',2 );

insert into Persona(cod_persona, nombre, apellido, fecha_registro)
 values( left(uuid(),12), 'Daniel', '8a', '2021-04-25' )
 
insert into CabeceraFactura(fecha_cab_fact, total_cab_fact)
 values( current_date(), 325.6 )

insert into Paquete(paq_descripcion,paq_price)
 values( 'Entrenamiento Mensual', 35.0),( 'Entrenamiento Diario', 3.0)
 
insert into Usuario(usuario, clave)
values ("Ivan", left(uuid(),10) ),
	   ("Administrador", "123456789A");
*/



/*
select concat(p.nombre," ",p.apellido) as nombre_completo, rol.rol_descricion 
from Persona as p, Rol as rol
where p.id_rol = rol.id_rol;
*/



/*
PRIMERA VERSIÓN DEL STORED PROCEDURE PARA CALCULAR EL TOTAL DE LA CABECERA DE LA FACTURA
delimiter //
create procedure update_cabecera_factura( in current_cabecera int)
begin
	declare total int default 0;
	select sum( Paquete.paq_price *  DetalleFactura.cantidad_paq )
	from DetalleFactura
	inner join Paquete on Paquete.id_paq = DetalleFactura.id_paq
	where DetalleFactura.id_cab_fact = current_cabecera
	into total;
	update CabeceraFactura set total_cab_fact = total where  CabeceraFactura.id_cab_fact = current_cabecera;
end //
delimiter ;

*/
