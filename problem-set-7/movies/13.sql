SELECT DISTINCT p.name
FROM people p
JOIN stars s ON p.id = s.person_id
JOIN movies m ON s.movie_id = m.id
JOIN stars kevin_s ON m.id = kevin_s.movie_id
JOIN people kevin ON kevin_s.person_id = kevin.id
WHERE kevin.name = 'Kevin Bacon' AND kevin.birth = 1958
  AND p.name != 'Kevin Bacon';
