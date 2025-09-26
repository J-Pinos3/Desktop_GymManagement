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
    peso numeric(6,2),
    fecha_registro date,
    id_rol int, 
    foreign key(id_rol) references Rol(id_rol)
);

create table if not exists Paquete(
	id_paq int auto_increment primary key,
    paq_descripcion varchar(200) not null,
    paq_price decimal(5,2) not null,
    paq_days int not null
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
    foreign key(id_cab_fact) references CabeceraFactura(id_cab_fact)
);

create table if not exists PlanElegido(
	id_plan_eleg int auto_increment primary key,
    id_deta_fact int,
    id_paq int,
    catidad_paq int,
    fecha_pago date,
    fecha_finalizacion date,
    foreign key (id_deta_fact) references DetalleFactura(id_deta_fact),
    foreign key (id_paq) references Paquete(id_paq)
);

create table if not exists Servicio(
	id_serv int auto_increment primary key,
    serv_titulo varchar(200),
    serv_price numeric(5,2)
);

create table if not exists ServicioElegido(
	id_serv_elegido int auto_increment primary key,
    id_deta_fact int,
    id_serv int,
    num_sesiones int,
    fecha_serv datetime,
    foreign key (id_deta_fact) references DetalleFactura(id_deta_fact),
    foreign key (id_serv) references Servicio(id_serv)
);

-- select * from Persona where nombre like 'Julio%';

select * from Rol; -- no eliminar
select * from Persona;
select * from Paquete; -- no eliminar
select * from CabeceraFactura;
select * from DetalleFactura;
select * from Usuario;
select * from PlanElegido;
select * from Servicio; -- no eliminar
select * from ServicioElegido;

/*25/09/2025 query for searching-filtering PAYMENT invoices by date or user code*/
SELECT DISTINCT
    CabFac.id_cab_fact,   CabFac.fecha_cab_fact, 
    CabFac.total_cab_fact,
    Pers.cod_persona,   Pers.apellido
FROM CabeceraFactura as CabFac
INNER JOIN Persona as Pers ON Pers.cod_persona = CabFac.cod_persona
WHERE 
    (
        CabFac.id_cab_fact IN (
            SELECT DISTINCT CabFac2.id_cab_fact 
            FROM CabeceraFactura as CabFac2
            JOIN DetalleFactura as Detf ON CabFac2.id_cab_fact = Detf.id_cab_fact
            JOIN PlanElegido as PE ON Detf.id_deta_fact = PE.id_deta_fact
        )
        OR CabFac.id_cab_fact NOT IN (
            SELECT DISTINCT id_cab_fact 
            FROM DetalleFactura 
            WHERE id_cab_fact IS NOT NULL
        )
    )
    AND
    (
        (CabFac.fecha_cab_fact BETWEEN '2024-09-23' AND CURDATE())
        OR 
        (Pers.cod_persona LIKE '%s5-d4f6s%')
    );
    
    
/*  DROP TABLES 24/09/2025 */


/*  DROP TABLES 17/09/2025 */


/* 07/09/2025 query para traer cuántas citas hay en una fecha dada */
select 
	Servel.fecha_serv,
    (select serv_titulo from  Servicio where Servicio.id_serv = Servel.id_serv) ,
    Pers.nombre, Pers.apellido
from ServicioElegido as Servel
left join DetalleFactura as Detf on Detf.id_deta_fact = Servel.id_deta_fact
left join CabeceraFactura as CabFac on CabFac.id_cab_fact = Detf.id_cab_fact
left join Persona as Pers on Pers.cod_persona = CabFac.cod_persona
where Servel.fecha_serv like '2024-09-23%';



/*23/08/2025 query para traer todos los usuarios al inicio y mostrar las fechas de pago y fin del plan de entreno */
select 
	Pers.cod_persona, Pers.nombre,
    Pers.apellido, Pers.peso,
    Pers.fecha_registro, Pers.id_rol,
    Ple.fecha_pago, Ple.fecha_finalizacion
from CabeceraFactura as CabFac
inner join Persona as Pers on Pers.cod_persona = CabFac.cod_persona
inner join DetalleFactura as DetF on Detf.id_cab_fact = CabFac.id_cab_fact
inner join PlanElegido as Ple on Ple.id_deta_fact = Detf.id_deta_fact
order by Ple.fecha_finalizacion Desc;

-- ALTERNATIVO
SELECT 
    Pers.cod_persona, 
    Pers.nombre,
    Pers.apellido, 
    Pers.peso,
    Pers.fecha_registro, 
    Pers.id_rol,
    Ple.fecha_pago, 
    Ple.fecha_finalizacion,
    -- Calcular si el plan está vigente
    CASE 
        WHEN CURDATE() BETWEEN Ple.fecha_pago AND Ple.fecha_finalizacion THEN 'Vigente'
        ELSE 'Caducado'
    END as estado
FROM CabeceraFactura as CabFac
INNER JOIN Persona as Pers ON Pers.cod_persona = CabFac.cod_persona
INNER JOIN DetalleFactura as DetF ON DetF.id_cab_fact = CabFac.id_cab_fact
INNER JOIN PlanElegido as Ple ON Ple.id_deta_fact = DetF.id_deta_fact
ORDER BY 
    estado DESC,  -- Primero los vigentes
    Ple.fecha_finalizacion DESC;  -- Luego por fecha más reciente





/* 22/08/2025 query para traer solo las facturas que sean de planes de ENTRENO del GYM
	y ttambién traer facturas nuevas vacías
1	Entrenamiento Mensual	35.00	30   tabla paquete
2	Entrenamiento Diario	3.00	1
*/
select distinct
	CabFac.id_cab_fact,
    CabFac.fecha_cab_fact,
	CabFac.total_cab_fact,
    Pers.cod_persona,
    Pers.nombre, Pers.apellido
from CabeceraFactura as CabFac
inner join Persona as Pers on Pers.cod_persona = CabFac.cod_persona
where CabFac.id_cab_fact in (
	-- facturas con planes de entreno
	select distinct CabFac2.id_cab_fact
    from CabeceraFactura as CabFac2
	JOIN DetalleFactura as DetF ON CabFac2.id_cab_fact = DetF.id_cab_fact
    JOIN PlanElegido as PE ON DetF.id_deta_fact = PE.id_deta_fact
    
    -- facturas sin detalles
) or
CabFac.id_cab_fact not in(
	select distinct id_cab_fact
    from DetalleFactura where id_cab_fact is not null ) ;




-- Query para traer todas las fechas donde hay una cita o servicio del gym y así marcarlas en el calendar
select substring(fecha_serv, 1, 10) as date_service
from ServicioElegido;

/* 17/04/2024 query para traer solo las facturas que sean de planes de ENTRENO del GYM
1	Entrenamiento Mensual	35.00	30   tabla paquete
2	Entrenamiento Diario	3.00	1
*/
select distinct
	CabFac.id_cab_fact,
    CabFac.fecha_cab_fact,
	CabFac.total_cab_fact,
    Pers.cod_persona,
    Pers.nombre, Pers.apellido
from CabeceraFactura as CabFac
inner join Persona as Pers on Pers.cod_persona = CabFac.cod_persona
left join DetalleFactura as DetF on CabFac.id_cab_fact = DetF.id_cab_fact
where DetF.id_deta_fact in ( select  id_deta_fact from PlanElegido  );


/* 14/04/2025 query para traer solo las facturas que sean de algún servicio del gym
1	Sesión de Fisioterapia	25.00		tabla servicio
2	Sesión de Nutricionismo	25.00       FUNCIONA
*/
select distinct
	CabFac.id_cab_fact,
    CabFac.fecha_cab_fact,
	CabFac.total_cab_fact,
    Pers.cod_persona,
    Pers.nombre, Pers.apellido
from CabeceraFactura as CabFac
inner join Persona as Pers on Pers.cod_persona = CabFac.cod_persona
left join DetalleFactura as DetF on CabFac.id_cab_fact = DetF.id_cab_fact
where DetF.id_deta_fact in ( select  id_deta_fact from ServicioElegido  );






-- función para traer todas las facturas normales y de las citas
select 
CabFact.id_cab_fact, CabFact.fecha_cab_fact,
CabFact.total_cab_fact, Pers.cod_persona
from CabeceraFactura as CabFact, Persona as Pers
where Pers.cod_persona = CabFact.cod_persona;


-- 25/03/2025 query para traer facturas en específico, o solo las de servicios o solo las de pagos normales
select * from PlanElegido;


-- inicio test factura de servicios 21-09-2024 todos los cambios fueron a la factura con id = 8, primero una venta de 50 usd y luego otra venta (sesión) de 25 total 75usd correcto
insert into CabeceraFactura(fecha_cab_fact, total_cab_fact)
 values( current_date(), 0.00 ); -- id18  update CabeceraFactura set cod_persona = '1afad6f5-6' where id_cab_fact = 9;


insert into DetalleFactura(total_deta_fact, id_cab_fact)
values (0.00, 8); -- id120 con la cabecera 8  id2 con la cabecera 8

insert into ServicioElegido(id_deta_fact, id_serv, num_sesiones, fecha_serv)
values(21, 1,1,'2024-09-23 11:30:45'); -- id1 1    id2 2


call update_detalle_servicio_factura(21);

call update_cabecera_factura(8);
-- fin test factura de servicios 21-09-2024


-- query para mostrar laS líneas de una cabecera elegida en general para el reporte AÑADIR EL NOMBRE DEL SERVICIO O EL PLAN
select
	Detf.id_deta_fact,
    Detf.total_deta_fact,
    if (Servel.num_sesiones <> -1 or Servel.num_sesiones is not null, Servi.serv_titulo , Paq.paq_descripcion) as Detalle ,
    if (Servel.num_sesiones <> -1 or Servel.num_sesiones is not null, Servel.fecha_serv, Ple.fecha_pago) as Fecha ,
    concat(Pers.nombre, ' ', Pers.apellido)
from DetalleFactura as Detf
left join CabeceraFactura as CabFact on Detf.id_cab_fact = CabFact.id_cab_fact
left join Persona as Pers on CabFact.cod_persona = Pers.cod_persona
left join ServicioElegido as Servel on Detf.id_deta_fact = Servel.id_deta_fact
left join Servicio as Servi on Servel.id_serv = Servi.id_serv
left join PlanElegido as Ple on Ple.id_deta_fact = Detf.id_deta_fact
left join Paquete as Paq on Ple.id_paq = Paq.id_paq
where Detf.id_cab_fact = 8;
-- fin del query que muestra las líneas de cada factura, para los reportes
select * from CabeceraFactura;

-- query mejorada para mostrar los detalles citas de algún servicio según la cabecera actual
select 
	Detf.id_deta_fact,
    concat(Servi.serv_titulo, ' ', Servi.serv_price),
    coalesce(Servel.num_sesiones,-1) as numSesiones,
    Detf.total_deta_fact,
    Servel.fecha_serv,
    concat( Pers.nombre, ' ', Pers.apellido )
    from DetalleFactura as Detf
    left join ServicioElegido as Servel on Detf.id_deta_fact = Servel.id_deta_fact
    left join Servicio as Servi on Servel.id_serv = Servi.id_serv
    left join CabeceraFactura as CabFact on Detf.id_cab_fact = CabFact.id_cab_fact
    left join Persona as Pers on CabFact.cod_persona = Pers.cod_persona
    where Detf.id_cab_fact = 3;
-- fin del query


-- query mejorada para mostrar los detalles de factura según la cabecera actual
select
	Detf.id_deta_fact,
    concat(Paq.paq_descripcion, " ",Paq.paq_price) as Descripcion,
    coalesce(Ple.id_paq, -1) as IdPaquete,
    coalesce(Ple.catidad_paq, -1) as Cantidad,
    Detf.total_deta_fact,
    Ple.fecha_pago, Ple.fecha_finalizacion
from DetalleFactura as Detf
-- and Paq.id_paq = Ple.id_paq ;
left join PlanElegido as Ple on Ple.id_deta_fact = Detf.id_deta_fact
left join Paquete as Paq on Ple.id_paq = Paq.id_paq
where Detf.id_cab_fact = 3;


-- query para mostrar el detalle de factura (según la cabecera actual) y mostrar los datos del paquete elegido
/*
select
	Detf.id_deta_fact, concat(Paq.paq_descripcion, " ",Paq.paq_price) as Descripcion,
    Ple.catidad_paq, Detf.total_deta_fact, Ple.fecha_pago, Ple.fecha_finalizacion
from DetalleFactura as Detf
inner join PlanElegido as Ple on Detf.id_deta_fact = Ple.id_deta_fact
inner join Paquete as Paq on Ple.id_paq = Paq.id_paq
where Detf.id_cab_fact = 7;
*/



select * from DetalleFactura where id_cab_fact = 7;
select * from Paquete where id_paq = 3;

insert into PlanElegido(id_deta_fact, id_paq, catidad_paq, fecha_pago, fecha_finalizacion)
values(2,1,1,'2021-01-01','2021-01-02'); -- también para el detalle 3 de la factura 3
call update_detalle_factura(3);
-- update DetalleFactura set total_deta_fact = 0.0 where id_cab_fact = 3;

insert into PlanElegido (id_deta_fact, id_paq, catidad_paq, fecha_pago, fecha_finalizacion)
values(16, 3, 1 ,'2024-8-25','2024-9-1');
call update_detalle_factura(16);



-- el valor de total deta será igual a id_paq * cantidad_paq, eso se calcula en el app c++
insert into DetalleFactura(total_deta_fact, id_cab_fact, id_paq, cantidad_paq)
 values( 70.0, 1, 1, 2);
insert into DetalleFactura(total_deta_fact, id_cab_fact, id_paq, cantidad_paq)
 values( 3.0, 1, 2, 1);
call update_cabecera_factura(3);
 
 
select * from Persona where  cod_persona = 'b8f61438-4';
 

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



delimiter $$
create procedure update_detalle_factura(in current_detalle int)
begin
	declare sub_total decimal default 0.0;
    select sum( Paq.paq_price * Pe.catidad_paq )
    from PlanElegido as Pe
    inner join Paquete as Paq on Paq.id_paq = Pe.id_paq
    where Pe.id_deta_fact = current_detalle
    into sub_total;
    IF sub_total < 0.0 THEN
		set sub_total = 0.0;
	END IF;
    update DetalleFactura set total_deta_fact = sub_total where DetalleFactura.id_deta_fact = current_detalle;
end $$
delimiter ;


delimiter **
create procedure update_detalle_servicio_factura(in current_detalle int)
begin
	declare sub_total decimal default 0.0;
    select( Servi.serv_price *  Servel.num_sesiones)
    from ServicioElegido as Servel
    inner join Servicio as Servi on Servel.id_serv = Servi.id_serv
    where Servel.id_deta_fact = current_detalle
    into sub_total;
    IF sub_total < 0.0 THEN
		set sub_total = 0.0;
    END IF;
    update DetalleFactura set total_deta_fact = sub_total where DetalleFactura.id_deta_fact = current_detalle;
end**
delimiter ;
/*
SET FOREIGN_KEY_CHECKS=0; --disable them
SET FOREIGN_KEY_CHECKS=1; --enable them*

insert into Servicio(serv_titulo, serv_price)
values ('Sesión de Fisioterapia', 25.00), ('Sesión de Nutricionismo', 25.00);

insert into Rol(rol_descricion)
values ('Cliente'),('Administrador'),('Entrenador'),('Nutricionista'),('Fisioterapeuta');

insert into Persona(cod_persona, nombre, apellido, fecha_registro, id_rol)
values( LEFT(uuid(),7), 'Jose', 'Pinos', '2024-04-25',2 );

insert into Persona(cod_persona, nombre, apellido, fecha_registro)
 values( left(uuid(),12), 'Daniel', '8a', '2021-04-25' )
 
insert into CabeceraFactura(fecha_cab_fact, total_cab_fact)
 values( current_date(), 325.6 )

insert into Paquete(paq_descripcion,paq_price,paq_days)
 values( 'Entrenamiento Mensual', 35.0, 30),( 'Entrenamiento Diario', 3.0, 1)
		,( 'Entrenamiento Semanal', 20.0, 7),( 'Entrenamiento Anual', 900.0, 375)

update Persona set id_rol = 1 where cod_persona = 'b8f61438-4';
 
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
