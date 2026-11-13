USE LAB2;

/* Visa alla kunder som inte bor i WA) */
select * from customer where zip != '98764';

/* Skriv ut alla djur med namn som börjar med R*/
select * from pets where pet_name LIKE 'R%';

/* Skriv ut besök skedde mellan specifika datum */
select * from visit where Date between '2025-08-16' AND '2025-08-29';

/* Visa hur många djur varje kund har */
select c_id, COUNT(*) as Antal_djur from pets GROUP BY c_id;

/* Visa kunder som har endast ett djut */
select c_id, COUNT(*) as antal_djur from pets group by c_id having count(*) < 2;

/* Lista alla tjnster sorterade efter pris i fallande ordning */
select * from service order by price DESC;

/* Ta bort alla husdjur som ör äldre än år 1998-01-02*/
/*delete from pets where birth_date < '1988-01-02'*/

/* lista namnen på de kunder som äger lika många djur som nummer 3*/
    select name from customer where customer_id in(select c_id from pets group by c_id having count(*) = (select count(*) from pets where c_id = 3));


