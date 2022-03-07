#include "dndobjects.h"
using namespace dndobjs;

QString dndobjs::DiceText(dice d)
{
    switch (d)
    {
    case (dice::d2):
        return "D2";
    case (dice::d4):
        return "D4";
    case (dice::d6):
        return "D6";
    case (dice::d8):
        return "D8";
    case (dice::d10):
        return "D10";
    case (dice::d12):
        return "D12";
    case (dice::d20):
        return "D20";
    case (dice::d100):
        return "D100";
    default:
        return "null";
    }
}
QString dndobjs::ObjTypeText(objType o)
{
    switch(o)
    {
    case (objType::adventutingGear):
        return "adventuring gear";
    case (objType::ammo):
        return "ammunition";
    case (objType::armour):
        return "armour";
    case (objType::potion):
        return "potion";
    case (objType::relic):
        return "relic";
    case (objType::ring):
        return "ring";
    case (objType::rod):
        return "rod";
    case (objType::scroll):
        return "scroll";
    case (objType::shield):
        return "shield";
    case (objType::staff):
        return "staff";
    case (objType::tool):
        return "tool";
    case (objType::wand):
        return "wand";
    case (objType::weapon):
        return "weapon";
    case (objType::wonderousItem):
        return "wonderous item";
    default:
        return "null";
    }
}
QString dndobjs::RarityText(rarity r)
{
    switch(r)
    {
    case (rarity::common):
        return "common";
    case (rarity::uncommon):
        return "uncommon";
    case (rarity::rare):
        return "rare";
    case (rarity::veryRare):
        return "very rare";
    case (rarity::legendary):
        return "legendary";
    default:
        return "null";
    }
}
QString dndobjs::WeaponPropertiesText(weaponProperties w)
{
    switch(w)
    {
    case (weaponProperties::ammunition):
        return "ammunition";
    case (weaponProperties::finesse):
        return "finesse";
    case (weaponProperties::heavy):
        return "heavy";
    case (weaponProperties::improv):
        return "improvised";
    case (weaponProperties::light):
        return "light";
    case (weaponProperties::loading):
        return "loading";
    case (weaponProperties::range):
        return "range";
    case (weaponProperties::reach):
        return "reach";
    case (weaponProperties::silvered):
        return "silvered";
    case (weaponProperties::special):
        return "special";
    case (weaponProperties::thrown):
        return "thrown";
    case (weaponProperties::twoHanded):
        return "two handed";
    case (weaponProperties::versatile):
        return "versatile";
    default:
        return "null";
    }
}
QString dndobjs::SizeText(size s)
{
    switch(s)
    {
    case (size::tiny):
        return "tiny";
    case (size::small):
        return "small";
    case (size::medium):
        return "medium";
    case (size::large):
        return "large";
    case (size::huge):
        return "huge";
    case (size::gargantuan):
        return "gargantuan";
    default:
        return "null";
    }
}
QString dndobjs::DamageTypeText(damageType d)
{
    switch(d)
    {
    case (damageType::acid):
        return "acid";
    case (damageType::bludgeoning):
        return "bludgeoning";
    case (damageType::cold):
        return "cold";
    case (damageType::fire):
        return "fire";
    case (damageType::force):
        return "force";
    case (damageType::lightning):
        return "lightning";
    case (damageType::necrotic):
        return "necrotic";
    case (damageType::piercing):
        return "piercing";
    case (damageType::poison):
        return "poison";
    case (damageType::psychic):
        return "psychic";
    case (damageType::radiant):
        return "radiant";
    case (damageType::slashing):
        return "slashing";
    case (damageType::thunder):
        return "thunder";
    default:
        return "null";
    }
}
QString dndobjs::ArmourTypeText(armourType a)
{
    switch(a)
    {
    case (armourType::lightArmour):
        return "light armour";
    case (armourType::medArmour):
        return "medium armour";
    case (armourType::heavyArmour):
        return "heavy armour";
    default:
        return "null";
    }
}
QString dndobjs::WeaponTypeText(weaponType w)
{
    switch(w)
    {
    case (weaponType::battleaxe):
        return "battleaxe";
    case (weaponType::blowgun):
        return "blowgun";
    case (weaponType::club):
        return "club";
    case (weaponType::crossbowHand):
        return "hand crossbow";
    case (weaponType::crossbowHeavy):
        return "heavy crossbow";
    case (weaponType::crossbowLight):
        return "light crossbow";
    case (weaponType::dagger):
        return "dagger";
    case (weaponType::dart):
        return "dart";
    case (weaponType::flail):
        return "flail";
    case (weaponType::glaive):
        return "glaive";
    case (weaponType::greatClub):
        return "great club";
    case (weaponType::greataxe):
        return "greataxe";
    case (weaponType::greatsword):
        return "greatsword";
    case (weaponType::halberd):
        return "halberd";
    case (weaponType::handAxe):
        return "hand axe";
    case (weaponType::javelin):
        return "javelin";
    case (weaponType::lance):
        return "lance";
    case (weaponType::lightHammer):
        return "light hammer";
    case (weaponType::longbow):
        return "longbow";
    case (weaponType::longsword):
        return "longsword";
    case (weaponType::mace):
        return "mace";
    case (weaponType::maul):
        return "maul";
    case (weaponType::morningstar):
        return "morningstar";
    case (weaponType::net):
        return "net";
    case (weaponType::pike):
        return "pike";
    case (weaponType::quaterstaff):
        return "quaterstaff";
    case (weaponType::rapier):
        return "rapier";
    case(weaponType::scimitar):
        return "scimitar";
    case (weaponType::scythe):
        return "scythe";
    case (weaponType::shortBow):
        return "short bow";
    case (weaponType::shortsword):
        return "shortsword";
    case (weaponType::sickle):
        return "sickle";
    case (weaponType::sling):
        return "sling";
    case (weaponType::spear):
        return "spear";
    case (weaponType::trident):
        return "trident";
    case (weaponType::warPick):
        return "war pick";
    case (weaponType::warhammer):
        return "warhammer";
    case (weaponType::whip):
        return "whip";
    case (weaponType::improvised):
        return "improvised";
    default:
        return "null";
    }
}
QString dndobjs::StatsText(stats s)
{
    switch (s)
    {
    case (stats::strength):
        return "strength";
    case (stats::dexterity):
        return "dexterity";
    case (stats::constitution):
        return "constitution";
    case (stats::intelligence):
        return "intelligence";
    case (stats::wisdom):
        return "wisdom";
    case (stats::charisma):
        return "charisma";
    default:
        return "null";
    }
}
QString dndobjs::StatsTextShort(stats s)
{
    switch (s)
    {
    case (stats::strength):
        return "STR";
    case (stats::dexterity):
        return "DEX";
    case (stats::constitution):
        return "CON";
    case (stats::intelligence):
        return "INT";
    case (stats::wisdom):
        return "WIS";
    case (stats::charisma):
        return "CHA";
    default:
        return "null";
    }
}
QString dndobjs::StatsText(int s)
{
    return StatsText((stats) s);
}
QString dndobjs::StatsTextShort(int s)
{
    return StatsTextShort((stats) s);
}
QString dndobjs::SkillsText(skills s)
{
    switch(s)
    {
    case (skills::acrobatics):
        return "acrobatics";
    case (skills::animalHandling):
        return "animal handling";
    case (skills::arcana):
        return "arcana";
    case (skills::athletics):
        return "athletics";
    case (skills::deception):
        return "deception";
    case (skills::history):
        return "history";
    case (skills::insight):
        return "insight";
    case (skills::intimidation):
        return "intimidation";
    case (skills::investigation):
        return "investigation";
    case (skills::medicine):
        return "medicine";
    case (skills::nature):
        return "nature";
    case (skills::perception):
        return "perception";
    case (skills::performance):
        return "performance";
    case (skills::persuasion):
        return "persuasion";
    case (skills::religion):
        return "religion";
    case (skills::sleightOfHand):
        return "sleight of hand";
    case (skills::stealth):
        return "stealth";
    case (skills::survival):
        return "survival";
    default:
        return "null";
    }
}
QString dndobjs::SkillsText(int s)
{
    return SkillsText((skills) s);
}
QString dndobjs::MagicSchoolText(magicSchools m)
{
    switch(m)
    {
    case (magicSchools::abjuration):
        return "abjuration";
    case (magicSchools::conjuration):
        return "conjuration";
    case (magicSchools::divination):
        return "divination";
    case (magicSchools::enchantment):
        return "enchantment";
    case (magicSchools::evocation):
        return "evocation";
    case (magicSchools::illusion):
        return "illusion";
    case (magicSchools::necromancy):
        return "necromancy";
    case (magicSchools::transumation):
        return "transumation";
    default:
        return "null";
    }
}
QString dndobjs::AlignmentText(alignment a)
{
    switch (a)
    {
    case (alignment::lg):
        return "lawful good";
    case (alignment::ln):
        return "lawful neutral";
    case (alignment::le):
        return "lawful evil";
    case (alignment::ng):
        return "neutral good";
    case (alignment::nn):
        return "true neutral";
    case (alignment::ne):
        return "neutral evil";
    case (alignment::cg):
        return "chaotic good";
    case (alignment::cn):
        return "chaotic neutral";
    case (alignment::ce):
        return "chaotic evil";
    default:
        return "null";
    }
}
QString dndobjs::CreatureTypeText(creatureType t)
{
    switch (t)
    {
    case (creatureType::abberation):
        return "abberation";
    case (creatureType::beast):
        return "beast";
    case (creatureType::celestial):
        return "celestial";
    case (creatureType::construct):
        return "construct";
    case (creatureType::dragon):
        return "dragon";
    case (creatureType::elemental):
        return "elemental";
    case (creatureType::fey):
        return "fey";
    case (creatureType::fiend):
        return "fiend";
    case (creatureType::giant):
        return "giant";
    case (creatureType::humanoid):
        return "humanoid";
    case (creatureType::monstrosity):
        return "monstrosity";
    case (creatureType::ooze):
        return "ooze";
    case (creatureType::plant):
        return "plant";
    case (creatureType::undead):
        return "undead";
    default:
        return "null";
    }
}
QString dndobjs::ConditionText(conditions c)
{
    switch(c)
    {
    case (conditions::blinded):
        return "blinded";
    case (conditions::charmed):
        return "charmed";
    case (conditions::deafened):
        return "deafened";
    case (conditions::frightened):
        return "frightnened";
    case (conditions::grappled):
        return "grappled";
    case (conditions::incapacitated):
        return "incapacitated";
    case (conditions::invisible):
        return "invisible";
    case (conditions::paralyzed):
        return "paralyzed";
    case (conditions::petrified):
        return "petrified";
    case (conditions::poisoned):
        return "poisoned";
    case (conditions::prone):
        return "prone";
    case (conditions::restrained):
        return "restrained";
    case (conditions::stunned):
        return "stunned";
    case (conditions::unconcious):
        return "unconcious";
    case (conditions::exh1):
        return "exhausted (1)";
    case (conditions::exh2):
        return "exhausted (2)";
    case (conditions::exh3):
        return "exhausted (3)";
    case (conditions::exh4):
        return "exhausted (4)";
    case (conditions::exh5):
        return "exhausted (5)";
    case (conditions::exh6):
        return "shouldnt you be dead?";
    default:
        return "null";
    }
}
QString dndobjs::LanguageText(language l)
{
    switch (l)
    {
    case (language::abyssalSpeech):
        return "abyssal";
    case (language::celestialSpeech):
        return "celestial";
    case (language::commonSpeech):
        return "common";
    case (language::deepSpeech):
        return "deep speech";
    case (language::draconicSpeech):
        return "draconic";
    case (language::dwarvishSpeech):
        return "dwarvish";
    case (language::elvishSpeech):
        return "elvish";
    case (language::giantSpeech):
        return "giant";
    case (language::gnomishSpeech):
        return "gnomish";
    case (language::goblinSpeech):
        return  "goblin";
    case (language::halflingSpeech):
        return "halfling";
    case (language::infernalSpeech):
        return "infernal";
    case (language::orcSpeech):
        return "orcish";
    case (language::primordialSpeech):
        return "primordial";
    case (language::sylvanSpeech):
        return "sylvan";
    case (language::undercommonSpeech):
        return "undercommon";
    default:
        return "null";
    }
}
QString dndobjs::EquipPosText(equipPos e)
{
    switch (e)
    {
    case (equipPos::crown):
        return "crown";
    case (equipPos::neck):
        return "neck";
    case (equipPos::torso):
        return "torso";
    case (equipPos::arms):
        return "arms";
    case (equipPos::finger):
        return "fingers";
    case (equipPos::back):
        return "back";
    case (equipPos::handLeft):
        return "left hand";
    case (equipPos::handRight):
        return "right hand";
    case (equipPos::gloves):
        return "gloves";
    case (equipPos::legs):
        return "legs";
    case (equipPos::belt):
        return "belt";
    case (equipPos::feet):
        return "feet";
    default:
        return "null";
    }
}
QString dndobjs::SpeedText(speedTypes s)
{
    switch (s)
    {
    case (speedTypes::walking):
        return "walking";
    case (speedTypes::climbing):
        return "climbing";
    case (speedTypes::swimming):
        return "swimming";
    case (speedTypes::flying):
        return "flying";
    default:
        return "null";
    }
}
QString dndobjs::SightText(sightTypes s)
{
    switch(s)
    {
    case (sightTypes::blindsight):
        return "blindsight";
    case (sightTypes::darkvision):
        return "darkvision";
    case (sightTypes::truesight):
        return "truesight";
    default:
        return "null";
    }
}

stats dndobjs::SkillStat(skills s)
{
    switch (s)
    {
    case skills::athletics:
        return strength;
    case skills::acrobatics: case skills::sleightOfHand: case skills::stealth:
        return dexterity;
    case skills::arcana: case skills::history: case skills::investigation: case skills::nature: case skills::religion:
        return intelligence;
    case skills::animalHandling: case skills::insight: case skills::medicine: case skills::perception: case skills::survival:
        return wisdom;
    case skills::deception: case skills::intimidation: case skills::performance: case skills::persuasion:
        return charisma;
    default:
        return strength;
    }
}

ushort GetProficincyFromLevel (ushort level)
{
    switch (level)
    {
    case 1: case 2: case 3: case 4:
        return 2;
    case 5: case 6: case 7: case 8:
        return 3;
    case 9: case 10: case 11: case 12:
        return 4;
    case 13: case 14: case 15: case 16:
        return 5;
    case 17: case 18: case 19: case 20:
        return 6;
    default:
        return 0;
    }
}

QString dndobjs::SignedModifierText(int modifier)
{
    return ((modifier == 0) ? "" : ((modifier >= 0) ? " + " : " - ") + QString::number(std::abs(modifier)));
}

DDDice::DDDice(dice newD, ushort newCount, short newModifier)
{
    this->d = newD;
    this->count = newCount;
    this->modifier = newModifier;
    this->next = nullptr;
}
DDDice::DDDice(dice newD, ushort newCount, short newModifier, DDDice *n)
{
    this->d = newD;
    this->count = newCount;
    this->modifier = newModifier;
    this->next = n;
}
DDDice::DDDice()
{
    this->count = -1;
}
QString DDDice::ToString () { return QString::number(count) + DiceText(d) + " " + SignedModifierText(modifier); }
QString DDDice::GetDiceText() { return DiceText(d); }
dice DDDice::GetDice() { return d; }
ushort DDDice::GetDiceCount() { return count; }
short DDDice::GetModifier() { return modifier; }
void DDDice::SetModifier(short i) { modifier = i; }
void DDDice::SetCount(ushort i) { count = i; }
DDDice* DDDice::Next() { return (MoreDice() ? next : this); }
bool DDDice::MoreDice() { return (this->next != nullptr); }
void DDDice::SetNext(DDDice *n)
{
    DDDice *current = this;
    while (current->MoreDice())
    {
        current = current->Next();
    }
    current->next = n;
}

DDDamageDice::DDDamageDice(dice newD, ushort newCount, short newModifier, damageType dt) :
    DDDice(newD, newCount, newModifier)
{
    this->dmgType = dt;
    this->next = nullptr;
}
DDDamageDice::DDDamageDice(dice newD, ushort newCount, short newModifier, damageType dt, DDDamageDice *n) :
    DDDice(newD, newCount, newModifier)
{
    this->dmgType = dt;
    this->next = n;
}
QString DDDamageDice::ToString () { return QString::number(count) + DiceText(d) + SignedModifierText(modifier) + " " + DamageTypeText(dmgType); }
QString DDDamageDice::GetDamageTypeText() { return DamageTypeText(dmgType); }
damageType DDDamageDice::GetDamageType() { return dmgType; }
void DDDamageDice::SetNext(DDDamageDice *n)
{
    DDDamageDice *current = this;
    while (current->MoreDice())
    {
        current = current->Next();
    }
    current->next = n;
}
DDDamageDice* DDDamageDice::Next() { return (MoreDice() ? next : this); }
bool DDDamageDice::MoreDice() { return (next != nullptr); }

DDShape::DDShape(ushort sz, QString sp)
{
    this->size = sz;
    this->shape = sp;
}
ushort DDShape::GetSize() { return size; }
QString DDShape::GetShape() { return shape; }

DDSpell::DDSpell (QString n, QString d, QString cT, QString dur, magicSchools s, ushort lvl, ushort r)
{
    this->name = n;
    this->description = d;
    this->castTime = cT;
    this->duration = dur;
    this->school = s;
    this->level = lvl;
    this->range = r;
}
DDSpell::DDSpell()
{
    this->name = "NULL";
}
QString DDSpell::GetName() { return name; }
QString DDSpell::GetDescription() { return description; }
QString DDSpell::GetCastTime() { return castTime; }
QString DDSpell::GetDuration() { return duration; }
QString DDSpell::GetSchoolText() { return MagicSchoolText(school); }
magicSchools DDSpell::GetSchool() { return school; }
ushort DDSpell::GetLevel() { return level; }
ushort DDSpell::GetRange() { return range; }
QString DDSpell::GetSpellComponentsText()
{
    QString rtrn;
    for (int i = 0; i < 3; i++)
    {
        if (spellComponents[i])
        {

        }
    }
    return rtrn;
}
bool DDSpell::GetSpellComponent(int index) { return spellComponents[index]; }
QString DDSpell::GetItemComponents() { return itemComponents; }
QString DDSpell::GetClassesText()
{
    QString rtrn;
    for (DDClass *c : classes)
    {
        rtrn += c->GetName() + ", ";
    }
    rtrn.chop(2);
    return rtrn;
}
DDClass* DDSpell::GetClass(int index) { return classes[index]; }
void DDSpell::AddClass (DDClass* c) { classes.push_back(c); }
void DDSpell::SetMagicComponents(bool v, bool s, bool i)
{
    spellComponents[0] = v;
    spellComponents[1] = s;
    spellComponents[2] = i;
}
void DDSpell::SetItemComponents(QString iC) { itemComponents = iC; }
ushort DDSpell::GetMetaType() { return 0; }

DDAttackSpell::DDAttackSpell (QString n, QString d, QString cT, QString dur, magicSchools s, ushort lvl, ushort r, DDDamageDice *dd) :
    DDSpell(n, d, cT, dur, s, lvl, r)
{
    this->dmgDie = dd;
}
DDAttackSpell::DDAttackSpell()
{
    this->name = "NULL";
}
QString DDAttackSpell::GetDmgDiceText()
{
    QString rtrn;
    DDDice *current = dmgDie;
    do
    {
        rtrn += (current->ToString() + (current->MoreDice() ? "," : ""));
        current = dmgDie->Next();
    } while (current->MoreDice());
    return rtrn;
}
DDDamageDice* DDAttackSpell::GetDamageDie(int index)
{
    DDDamageDice *rtrn = dmgDie;
    for (int i = 0; i < index; i++)
    {
        rtrn = rtrn->Next();
    }
    return rtrn;
}
ushort DDAttackSpell::GetMetaType() { return 1; }

DDAOESpell::DDAOESpell (QString n, QString d, QString cT, QString dur, magicSchools s, ushort lvl, ushort r, ushort sz, QString sH) :
    DDSpell(n, d, cT, dur, s, lvl, r), DDShape(sz, sH) { }
QString DDAOESpell::GetShape() { return shape; }
ushort DDAOESpell::GetSize() { return size; }
ushort DDAOESpell::GetMetaType() { return 2; }

DDAOEAttackSpell::DDAOEAttackSpell (QString n, QString d, QString cT, QString dur, magicSchools s, ushort lvl, ushort r, DDDamageDice *dd, ushort sz, QString sH) :
    DDAttackSpell(n, d, cT, dur, s, lvl, r, dd), DDShape(sz, sH){ }
ushort DDAOEAttackSpell::GetMetaType() { return 3; }

DDHealingSpell::DDHealingSpell (QString n, QString d, QString cT, QString dur, magicSchools s, ushort lvl, ushort r, DDDice* hD) :
    DDSpell(n, d, cT, dur, s, lvl, r)
{
    this->healDice = hD;
}
DDDice* DDHealingSpell::GetDice() { return healDice; }
QString DDHealingSpell::GetDiceText() { return healDice->GetDiceText(); }
ushort DDHealingSpell::GetMetaType() { return 4; }

DDSpecialProperty::DDSpecialProperty(QString n, QString d, void* f, int v, specialpropertyTypes t)
{
    this->name = n;
    this->description = d;
    this->func = f;
    this->valChange = v;
    this->type = t;
}
DDSpecialProperty::DDSpecialProperty(QString n, QString d, specialpropertyTypes t)
{
    this->name = n;
    this->description = d;
    this->type = t;
}
DDSpecialProperty::DDSpecialProperty()
{
    this->name = "NULL";
}
QString DDSpecialProperty::GetName() { return name; }
QString DDSpecialProperty::GetDescription() { return description; }
QString DDSpecialProperty::ToString() { return this->GetName() + ": " + this->GetDescription(); }
specialpropertyTypes DDSpecialProperty::GetType() { return type; }

DDSpellProperty::DDSpellProperty(QString n, QString d, void* f, int v, specialpropertyTypes t, DDSpell* s, ushort mc) :
    DDSpecialProperty(n, d, f, v, t)
{
    this->spell = s;
    this->maxCharges = mc;
    this->charges = mc;
}
QString DDSpellProperty::GetDescription()
{
    return description + "\n\n" + spell->GetName() + ": " + spell->GetDescription();
}
void DDSpellProperty::UseCharge()
{
    if (charges > 0)
    {
        charges--;
    }
}
void DDSpellProperty::RefillCharges()
{
    charges = maxCharges;
}
void DDSpellProperty::SetCharge(ushort c)
{
    if (c <= maxCharges)
    {
        charges = c;
    }
}

DDSpecialAttack::DDSpecialAttack(QString n, QString d, void* f, int v, specialpropertyTypes t, DDDamageDice *dd) :
    DDSpecialProperty(n, d, f, v, t)
{
    this->dmgDie = dd;
}
QString DDSpecialAttack::GetDescription()
{
    return description;
}

DDSpecialPoints::DDSpecialPoints(QString n, QString d, void* f, int v, specialpropertyTypes t, QString pN, ushort p) :
    DDSpecialProperty(n, d, f, v, t)
{
    this->pointsName = pN;
    this->maxPoints = p;
    this->points = p;
}
QString DDSpecialPoints::GetDescription()
{
    return description + "\n" + pointsName + ": " + QString::number(points) + " / " + QString::number(maxPoints);
}
ushort DDSpecialPoints::GetPoints() { return points; }
ushort DDSpecialPoints::GetMaxPoints() { return maxPoints; }
void DDSpecialPoints::UseCharge() { if (points > 0) { points--; } }
void DDSpecialPoints::RegainCharge() { if (points < maxPoints) { points++; } }
void DDSpecialPoints::RefillCharges() { points = maxPoints; }
void DDSpecialPoints::SetMaxCharges(int i) { maxPoints = i; if (points > maxPoints) { points = maxPoints; } }

DDObject::DDObject(QString n, QString d, objType t, equipPos eq, rarity r, size s, float p)
{
    this->name = n;
    this->description = d;
    this->type = t;
    this->eqiupPosition = eq;
    this->objRarity = r;
    this->objSize = s;
    this->price = p;
}
DDObject::DDObject()
{
    this->name = "NULL";
}
QString DDObject::GetName() { return name; }
QString DDObject::GetDescription() { return description; }
QString DDObject::GetTypeText() { return ObjTypeText(type); }
objType DDObject::GetType() { return type; }
QString DDObject::GetEquipmentPositionText() { return EquipPosText(eqiupPosition); }
equipPos DDObject::GetEquipmentPosition() { return eqiupPosition; }
QString DDObject::GetRarityText() { return RarityText(objRarity); }
rarity DDObject::GetRarity() { return objRarity; }
QString DDObject::GetSpecialPropertyText()
{
    QString rtrn;
    for (DDSpecialProperty *special : specialProperties)
    {
        rtrn += special->GetName() + ": " + special->GetDescription() + "\n"; //here it is! heres the broken one
    }
    rtrn.chop(1);
    return rtrn;
}
DDSpecialProperty* DDObject::GetSpecialProperty(int index) { return specialProperties[index]; }
float DDObject::GetPrice() { return price; }
QString DDObject::GetPriceText()
{
    if (price < 0.1)
    {
        return QString::number(price * 100) + " copper";
    }
    else if (price < 1)
    {
        return QString::number(price * 10) + " silver";
    }
    else
    {
        return QString::number(price) + " gold";
    }
}
QString DDObject::GetSizeText() { return SizeText(objSize); }
size DDObject::GetSize() { return objSize; }
ushort DDObject::GetSpecialPropertyCount() { return specialProperties.size(); }
void DDObject::AddSpecialProperty(DDSpecialProperty* newP) { specialProperties.push_back(newP); }
std::vector<DDSpellProperty*> DDObject::GetSpellProperties()
{
    std::vector<DDSpellProperty*> rtrn;

    for (DDSpecialProperty* sp : specialProperties)
    {
        if (sp->GetType() == spellProperty)
        {
            rtrn.push_back(dynamic_cast<DDSpellProperty*>(sp));
        }
    }

    return rtrn;
}
std::vector<DDSpecialPoints*> DDObject::GetSpecialPoints()
{
    std::vector<DDSpecialPoints*> rtrn;

    for (DDSpecialProperty* sp : specialProperties)
    {
        if (sp->GetType() == pointProperty)
        {
            rtrn.push_back(dynamic_cast<DDSpecialPoints*>(sp));
        }
    }

    return rtrn;
}
std::vector<DDSpecialAttack*> DDObject::GetSpecialAttacks()
{
    std::vector<DDSpecialAttack*> rtrn;

    for (DDSpecialProperty* sp : specialProperties)
    {
        if (sp->GetType() == attackProperty)
        {
            rtrn.push_back(dynamic_cast<DDSpecialAttack*>(sp));
        }
    }

    return rtrn;
}

DDWeapon::DDWeapon(QString n, QString d, rarity r, size s, float p, weaponType t, DDDamageDice *dd, std::vector<weaponProperties> wp, bool mgic, bool mrtl, ushort ra) :
    DDObject(n, d, weapon, handRight, r, s, p)
{
    this->dmgDie = dd;
    this->properties = wp;
    this->magicLevel = mgic;
    this->isMartial = mrtl;
    this->range = ra;
    this->wpnType = t;
}
DDWeapon::DDWeapon(QString n, QString d, weaponType t, ushort diceCount, ushort mgicLevel, rarity r, ushort p)
{
    this->name = n;
    this->description = d;
    this->wpnType = t;
    this->type = weapon;
    this->eqiupPosition = handRight;
    this->magicLevel = mgicLevel;
    this->description = "A weapon that you may use.";
    this->objRarity = r;
    switch (wpnType)
    {
    case (weaponType::battleaxe):
        this->dmgDie = new DDDamageDice(d8, diceCount, mgicLevel, slashing, new DDDamageDice(d10, diceCount, mgicLevel, slashing));
        properties.push_back(versatile);
        this->objSize = medium;
        this->isMartial = true;
        this->price = (p == 0) ? 10 : p;
        break;
    case (weaponType::blowgun):
        this->dmgDie = new DDDamageDice(d4, diceCount, mgicLevel, piercing);
        properties.push_back(ammunition); properties.push_back(light); properties.push_back(loading);
        this->isMartial = true;
        this->range = 100;
        this->price = (p == 0) ? 10 : p;
        break;
    case (weaponType::club):
        this->dmgDie = new DDDamageDice(d4, diceCount, mgicLevel, bludgeoning);
        properties.push_back(light);
        this->isMartial = false;
        this->price = (p == 0) ? 0.1f : p;
        break;
    case (weaponType::crossbowHand):
        this->dmgDie = new DDDamageDice(d6, diceCount, mgicLevel, piercing);
        properties.push_back(light); properties.push_back(ammunition); properties.push_back(loading);
        this->isMartial = true;
        this->range = 120;
        this->price = (p == 0) ? 75 : p;
        break;
    case (weaponType::crossbowHeavy):
        this->dmgDie = new DDDamageDice(d10, diceCount, mgicLevel, piercing);
        properties.push_back(heavy); properties.push_back(ammunition); properties.push_back(loading); properties.push_back(twoHanded);
        this->isMartial = true;
        this->range = 400;
        this->price = (p == 0) ? 50 : p;
        break;
    case (weaponType::crossbowLight):
        this->dmgDie = new DDDamageDice(d8, diceCount, mgicLevel, piercing);
        properties.push_back(ammunition); properties.push_back(loading); properties.push_back(twoHanded);
        this->isMartial = false;
        this->range = 400;
        this->price = (p == 0) ? 25 : p;
        break;
    case (weaponType::dagger):
        this->dmgDie = new DDDamageDice(d4, diceCount, mgicLevel, piercing);
        properties.push_back(finesse); properties.push_back(light); properties.push_back(thrown);
        this->isMartial = false;
        this->range = 60;
        this->price = (p == 0) ? 2 : p;
        break;
    case (weaponType::dart):
        this->dmgDie = new DDDamageDice(d4, diceCount, mgicLevel, piercing);
        properties.push_back(finesse); properties.push_back(thrown);
        this->isMartial = false;
        this->range = 60;
        this->price = (p == 0) ? 0.05 : p;
        break;
    case (weaponType::flail):
        this->dmgDie = new DDDamageDice(d8, diceCount, mgicLevel, bludgeoning);
        this->isMartial = true;
        this->price = (p == 0) ? 10 : p;
        break;
    case (weaponType::glaive):
        this->dmgDie = new DDDamageDice(d10, diceCount, mgicLevel, bludgeoning);
        properties.push_back(heavy); properties.push_back((weaponProperties) reach); properties.push_back(twoHanded);
        this->isMartial = true;
        this->price = (p == 0) ? 20 : p;
        break;
    case (weaponType::greatClub):
        this->dmgDie = new DDDamageDice(d8, diceCount, mgicLevel, bludgeoning);
        properties.push_back(twoHanded);
        this->isMartial = false;
        this->price = (p == 0) ? 0.2f : p;
        break;
    case (weaponType::greataxe):
        this->dmgDie = new DDDamageDice(d12, diceCount, mgicLevel, slashing);
        properties.push_back(twoHanded); properties.push_back(heavy);
        this->isMartial = true;
        this->price = (p == 0) ? 30 : p;
        break;
    case (weaponType::greatsword):
        this->dmgDie = new DDDamageDice(d6, (diceCount == 1) ? 2 : diceCount, mgicLevel, slashing);
        properties.push_back(twoHanded); properties.push_back(heavy);
        this->isMartial = true;
        this->price = (p == 0) ? 50 : p;
        break;
    case (weaponType::halberd):
        this->dmgDie = new DDDamageDice(d10, diceCount, mgicLevel, slashing);
        properties.push_back(twoHanded); properties.push_back(heavy); properties.push_back((weaponProperties) reach);
        this->isMartial = true;
        this->price = (p == 0) ? 20 : p;
        break;
    case (weaponType::handAxe):
        this->dmgDie = new DDDamageDice(d6, diceCount, mgicLevel, slashing);
        properties.push_back(light); properties.push_back(thrown);
        this->isMartial = false;
        this->price = (p == 0) ? 5 : p;
        this->range = 60;
        break;
    case (weaponType::javelin):
        this->dmgDie = new DDDamageDice(d6, diceCount, mgicLevel, piercing);
        properties.push_back(thrown);
        this->isMartial = false;
        this->price = (p == 0) ? 0.5f : p;
        this->range = 120;
        break;
    case (weaponType::lance):
        this->dmgDie = new DDDamageDice(d12, diceCount, mgicLevel, piercing);
        properties.push_back((weaponProperties) reach); properties.push_back(special);
        this->isMartial = true;
        this->price = (p == 0) ? 10 : p;
        break;
    case (weaponType::lightHammer):
        this->dmgDie = new DDDamageDice(d4, diceCount, mgicLevel, bludgeoning);
        properties.push_back(light); properties.push_back(thrown);
        this->isMartial = false;
        this->price = (p == 0) ? 2 : p;
        this->range = 60;
        break;
    case (weaponType::longbow):
        this->dmgDie = new DDDamageDice(d8, diceCount, mgicLevel, piercing);
        properties.push_back(ammunition); properties.push_back(heavy); properties.push_back(twoHanded);
        this->isMartial = true;
        this->price = (p == 0) ? 50 : p;
        this->range = 600;
        break;
    case (weaponType::longsword):
        this->dmgDie = new DDDamageDice(d8, diceCount, mgicLevel, slashing, new DDDamageDice(d10, diceCount, mgicLevel, slashing));
        properties.push_back(versatile);
        this->isMartial = true;
        this->price = (p == 0) ? 15 : p;
        break;
    case (weaponType::mace):
        this->dmgDie = new DDDamageDice(d6, diceCount, mgicLevel, bludgeoning);
        this->isMartial = false;
        this->price = (p == 0) ? 5 : p;
        break;
    case (weaponType::maul):
        this->dmgDie = new DDDamageDice(d6, (diceCount == 1) ? 2 : diceCount, mgicLevel, bludgeoning);
        properties.push_back(heavy); properties.push_back(twoHanded);
        this->isMartial = true;
        this->price = (p == 0) ? 10 : p;
        break;
    case (weaponType::morningstar):
        this->dmgDie = new DDDamageDice(d8, diceCount, mgicLevel, piercing);
        this->isMartial = true;
        this->price = (p == 0) ? 15 : p;
        break;
    case (weaponType::net):
        properties.push_back(special); properties.push_back(thrown);
        this->isMartial = true;
        this->price = (p == 0) ? 1 : p;
        this->range = 15;
        break;
    case (weaponType::pike):
        this->dmgDie = new DDDamageDice(d10, diceCount, mgicLevel, piercing);
        properties.push_back(heavy); properties.push_back((weaponProperties) reach); properties.push_back(twoHanded);
        this->isMartial = true;
        this->price = (p == 0) ? 5 : p;
        break;
    case (weaponType::quaterstaff):
        this->dmgDie = new DDDamageDice(d6, diceCount, mgicLevel, bludgeoning, new DDDamageDice(d8, diceCount, mgicLevel, bludgeoning));
        properties.push_back(versatile);
        this->isMartial = false;
        this->price = (p == 0) ? 0.2 : p;
        break;
    case (weaponType::rapier):
        this->dmgDie = new DDDamageDice(d8, diceCount, mgicLevel, piercing);
        properties.push_back(finesse);
        this->isMartial = true;
        this->price = (p == 0) ? 25 : p;
        break;
    case(weaponType::scimitar):
        this->dmgDie = new DDDamageDice(d6, diceCount, mgicLevel, slashing);
        properties.push_back(finesse); properties.push_back(light);
        this->isMartial = true;
        this->price = (p == 0) ? 25 : p;
        break;
    case (weaponType::scythe):
        this->dmgDie = new DDDamageDice(d4, (diceCount == 1) ? 2 : diceCount, mgicLevel, slashing);
        properties.push_back(heavy); properties.push_back(twoHanded);
        this->isMartial = false;
        this->price = (p == 0) ? 2 : p;
        break;
    case (weaponType::shortBow):
        this->dmgDie = new DDDamageDice(d10, diceCount, mgicLevel, piercing);
        properties.push_back(ammunition); properties.push_back(twoHanded);
        this->isMartial = false;
        this->price = (p == 0) ? 25 : p;
        this->range = 320;
        break;
    case (weaponType::shortsword):
        this->dmgDie = new DDDamageDice(d6, diceCount, mgicLevel, piercing);
        properties.push_back(finesse); properties.push_back(light);
        this->isMartial = true;
        this->price = (p == 0) ? 10 : p;
        break;
    case (weaponType::sickle):
        this->dmgDie = new DDDamageDice(d4, diceCount, mgicLevel, slashing);
        properties.push_back(light);
        this->isMartial = false;
        this->price = (p == 0) ? 1 : p;
        break;
    case (weaponType::sling):
        this->dmgDie = new DDDamageDice(d4, diceCount, mgicLevel, bludgeoning);
        properties.push_back(ammunition);
        this->isMartial = false;
        this->price = (p == 0) ? 0.1f : p;
        this->range = 120;
        break;
    case (weaponType::spear):
        this->dmgDie = new DDDamageDice(d6, diceCount, mgicLevel, piercing, new DDDamageDice(d8, diceCount, mgicLevel, piercing));
        properties.push_back(thrown); properties.push_back(versatile);
        this->isMartial = false;
        this->price = (p == 0) ? 1 : p;
        this->range = 60;
        break;
    case (weaponType::trident):
        this->dmgDie = new DDDamageDice(d6, diceCount, mgicLevel, piercing, new DDDamageDice(d8, diceCount, mgicLevel, piercing));
        properties.push_back(thrown); properties.push_back(versatile);
        this->isMartial = true;
        this->price = (p == 0) ? 5 : p;
        this->range = 60;
        break;
    case (weaponType::warPick):
        this->dmgDie = new DDDamageDice(d8, diceCount, mgicLevel, piercing);
        this->isMartial = true;
        this->price = (p == 0) ? 5 : p;
        break;
    case (weaponType::warhammer):
        this->dmgDie = new DDDamageDice(d8, diceCount, mgicLevel, bludgeoning, new DDDamageDice(d10, diceCount, mgicLevel, bludgeoning));
        properties.push_back(versatile);
        this->isMartial = true;
        this->price = (p == 0) ? 15 : p;
        break;
    case (weaponType::whip):
        this->dmgDie = new DDDamageDice(d4, diceCount, mgicLevel, slashing);
        properties.push_back(finesse); properties.push_back((weaponProperties) reach);
        this->isMartial = true;
        this->price = (p == 0) ? 2 : p;
        break;
    case (weaponType::improvised):
        break;
    }
}
QString DDWeapon::GetDieText()
{
    QString rtrn;

    if (this->HasWeaponProperty(versatile))
    {
        rtrn = QString::number(dmgDie->GetDiceCount()) + DiceText(dmgDie->GetDice()) + "/" + QString::number(dmgDie->Next()->GetDiceCount()) + DiceText(dmgDie->Next()->GetDice())
                + SignedModifierText(dmgDie->GetModifier()) + " " + DamageTypeText(dmgDie->GetDamageType());
        DDDamageDice *current = dmgDie->Next()->Next();
        while (current->MoreDice())
        {
            rtrn += "  + " + current->ToString();
            current = current->Next();
        }
    }
    else
    {
        DDDamageDice *current = dmgDie;
        do
        {
            rtrn += current->ToString() + (current->MoreDice() ? " + " : "");
            current = current->Next();
        } while (current->MoreDice());
    }
    return rtrn;
}
DDDamageDice* DDWeapon::GetDie(int index)
{
    DDDamageDice *rtrn = dmgDie;
    for (int i = 0; i < index; i++)
    {
        rtrn = rtrn->Next();
    }
    return rtrn;
}
ushort DDWeapon::GetDieCount()
{
    ushort rtrn = 1;
    DDDamageDice *d = dmgDie;
    while (d->MoreDice())
    {
        rtrn++;
        d = d->Next();
    }
    return rtrn;
}
bool DDWeapon::IsMagical() { return magicLevel; }
bool DDWeapon::IsMartial() { return isMartial; }
ushort DDWeapon::GetRange() { return range; }
ushort DDWeapon::GetMagicLevel() { return magicLevel; }
QString DDWeapon::GetWeaponPropertiesText()
{
    QString rtrn;
   for (int i = 0; i < (int)properties.size(); i++)
   {
       rtrn += WeaponPropertiesText(properties[i]);
       if (i < (int)properties.size() - 1)
       {
           rtrn += ", ";
       }
   }
   return rtrn;
}
weaponProperties DDWeapon::GetWeaponProperty(int index) { return properties[index]; }
bool DDWeapon::HasWeaponProperty(weaponProperties p)
{
    for (weaponProperties wp : properties)
    {
        if (wp == p)
        {
            return true;
        }
    }
    return false;
}
weaponType DDWeapon::GetWeaponType() { return wpnType; }
QString DDWeapon::GetWeaponTypeText() { return WeaponTypeText(wpnType); }

DDShield::DDShield (QString n, QString d, rarity r, size s, float p, ushort ac) :
    DDObject(n, d, shield, handLeft, r, s, p)
{
    this->acBonus = ac;
}
ushort DDShield::GetACBonus() { return acBonus; }

DDArmour::DDArmour (QString n, QString d, rarity r, size s, float p, ushort a, std::vector<skills> dadv, std::vector<skills> adv, armourType at) :
    DDObject(n, d, armour, torso, r, s, p)
{
    this->ac = a;
    this->advantages = adv;
    this->disadvantages = dadv;
    this->armType = at;
}
ushort DDArmour::GetAC() { return ac; }
QString DDArmour::GetAdvantagesText()
{
    QString rtrn = "Advantages: ";
    for (int i = 0; i < (int)advantages.size(); i++)
    {
        rtrn += SkillsText(advantages[i]);
        if (i < (int)advantages.size() - 1)
        {
            rtrn += ", ";
        }
    }
    return rtrn;
}
QString DDArmour::GetDisadvantagesText()
{
    QString rtrn = "Disadvantages: ";
    for (int i = 0; i < (int)disadvantages.size(); i++)
    {
        rtrn += SkillsText(advantages[i]);
        if (i < (int)disadvantages.size() - 1)
        {
            rtrn += ", ";
        }
    }
    return rtrn;
}
skills DDArmour::GetAdvantage(int index) { return advantages[index]; }
skills DDArmour::GetDisadvantage(int index) { return disadvantages[index]; }
armourType DDArmour::GetType() { return armType; }
QString DDArmour::GetTypeText() { return ArmourTypeText(armType); }

DDCreature::DDCreature(QString n, QString d, size s, creatureType t, alignment a, ushort shr[2], ushort stt[6], std::vector<enum skills> skprof, std::vector<enum stats> svprof, ushort profBonus, DDDice *hd, std::vector<damageType> dI, std::vector<damageType> dR, std::vector<damageType> dV, std::vector<DDSpecialProperty*> sp, std::vector<DDSpell*> spll, std::vector<language> lng)
{
    this->name = n;
    this->description = d;
    this->creatureSize = s;
    this->type = t;
    this->align = a;
    this->maxHp = shr[0];
    this->hp = maxHp;
    this->ac = shr[1];

    for (int i = 0; i < 6; i++)
    {
        stats[i] = stt[i];
        savingThrows[i] = (stt[i] - 10) / 2;
    }

    this->proficiencyBonus = profBonus;
    this->skillProficiencies = skprof;
    this->savingThrowProficiencies = svprof;
    this->initBonus = (stats[dexterity] - 10) / 2;
    this->hitDie = hd;
    this->dmgImmunities = dI;
    this->dmgResistances = dR;
    this->dmgVulnarabilities = dV;
    this->specialProperties = sp;
    this->spells = spll;
    this->languages = lng;
    GetSkillsFromStats();
}
DDCreature::DDCreature()
{
    this->name = "NULL";
}
void DDCreature::GetSkillsFromStats()
{
    for (int i = 0; i < 18; i++)
    {
        skills[i] = (stats[SkillStat(static_cast<enum skills>(i))] - 10) / 2;
    }
    for (enum skills sk : skillProficiencies)
    {
        skills[sk] += proficiencyBonus;
    }
    for (enum stats st : savingThrowProficiencies)
    {
        savingThrows[st] += proficiencyBonus;
    }
}
QString DDCreature::GetName() { return name; }
QString DDCreature::GetDescription() { return description; }
QString DDCreature::GetSizeText() { return SizeText(creatureSize); }
size DDCreature::GetSize() { return creatureSize; }
QString DDCreature::GetTypeText() { return CreatureTypeText(type); }
creatureType DDCreature::GetType() { return type; }
QString DDCreature::GetAlignmentText() { return AlignmentText(align); }
alignment DDCreature::GetAlignment() { return align; }
ushort DDCreature::GetAC() { return ac; }
ushort DDCreature::GetHP() { return hp; }
ushort DDCreature::GetMaxHP() { return maxHp; }
ushort DDCreature::GetSpeed(speedTypes sp) { return speed[sp]; }
ushort DDCreature::GetSight(sightTypes si) { return sight[si]; }
ushort DDCreature::GetStat(enum stats s) { return stats[s]; }
ushort DDCreature::GetStat(int s) { return stats[s]; }
ushort DDCreature::GetSpecialPropertyCount() { return specialProperties.size(); }
DDSpell* DDCreature::GetSpell(int index) { return spells[index]; }
ushort DDCreature::GetSpellCount() { return spells.size(); }
short DDCreature::GetStatModifier(enum stats stat) { return (stats [stat] - 10) / 2; }
short DDCreature::GetStatModifier(int stat) { return (stats [stat] - 10) / 2; }
short DDCreature::GetSavingThrow(enum stats s) { return savingThrows[s]; }
short DDCreature::GetSavingThrow(int s) { return savingThrows[s]; }
short DDCreature::GetSkill(enum skills skill) { return skills[skill]; }
short DDCreature::GetSkill(int skill) { return skills[skill]; }
short DDCreature::GetInitBonus() { return initBonus; }
short DDCreature::GetProficiencyBonus() { return proficiencyBonus; }
QString DDCreature::GetHitDiceText()
{
    QString rtrn;
    DDDice *current = hitDie;

    do
    {
        rtrn += current->ToString() + (current->MoreDice() ? " + " : "");
        current = current->Next();
    } while (current->MoreDice());

    return rtrn;
}
DDDice* DDCreature::GetHitDie (int index)
{
    DDDice *rtrn;
    for (int i = 0; i < index; i++)
    {
        rtrn = rtrn->Next();
    }
    return rtrn;
}
QString DDCreature::GetImmunityText()
{
    QString rtrn;
    for (int i = 0; i < (int)dmgImmunities.size(); i++)
    {
        rtrn += DamageTypeText(dmgImmunities[i]);
        if (i < (int)dmgImmunities.size() - 1)
        {
            rtrn += ", ";
        }
    }
    return rtrn;
}
QString DDCreature::GetResistanceText()
{
    QString rtrn;
    for (int i = 0; i < (int)dmgResistances.size(); i++)
    {
        rtrn += DamageTypeText(dmgResistances[i]);
        if (i < (int)dmgResistances.size() - 1)
        {
            rtrn += ", ";
        }
    }
    return rtrn;
}
QString DDCreature::GetVulnarabilityText()
{
    QString rtrn;
    for (int i = 0; i < (int)dmgVulnarabilities.size(); i++)
    {
        rtrn += DamageTypeText(dmgVulnarabilities[i]);
        if (i < (int)dmgVulnarabilities.size() - 1)
        {
            rtrn += ", ";
        }
    }
    return rtrn;
}
damageType DDCreature::GetImmunity(int index) { return dmgImmunities[index]; }
damageType DDCreature::GetResistance(int index) { return dmgResistances[index]; }
damageType DDCreature::GetVulnarability(int index) { return dmgVulnarabilities[index]; }
QString DDCreature::GetSpecialPropertyText()
{
    QString rtrn;
    for (int i = 0; i < (int)specialProperties.size(); i++)
    {
        rtrn += specialProperties[i]->GetName() + " : " + specialProperties[i]->GetDescription();
        if (i < (int)specialProperties.size() - 1)
        {
            rtrn += ", ";
        }
    }
    return rtrn;
}
DDSpecialProperty* DDCreature::GetSpecialProperty(int index) { return specialProperties[index]; }
bool DDCreature::IsProficient(enum skills s)
{
    for (enum skills sk : skillProficiencies)
    {
        if (s == sk)
        {
            return true;
        }
    }
    return false;
}
bool DDCreature::IsProficient(enum stats s)
{
    for (enum stats st : savingThrowProficiencies)
    {
        if (s == st)
        {
            return true;
        }
    }
    return false;
}
QString DDCreature::GetLanguagesText()
{
    QString rtrn;
    for (int i = 0; i < (int)languages.size(); i++)
    {
        rtrn += LanguageText(languages[i]);
        if (i < (int)languages.size() - 1)
        {
            rtrn += ", ";
        }
    }
    return rtrn;
}
language DDCreature::GetLangauge(int index) { return languages[index]; }
std::vector<DDSpellProperty*> DDCreature::GetSpellProperties()
{
    std::vector<DDSpellProperty*> rtrn;

    for (DDSpecialProperty* sp : specialProperties)
    {
        if (sp->GetType() == spellProperty)
        {
            rtrn.push_back(dynamic_cast<DDSpellProperty*>(sp));
        }
    }

    return rtrn;
}
std::vector<DDSpecialPoints*> DDCreature::GetSpecialPoints()
{
    std::vector<DDSpecialPoints*> rtrn;

    for (DDSpecialProperty* sp : specialProperties)
    {
        if (sp->GetType() == pointProperty)
        {
            rtrn.push_back(dynamic_cast<DDSpecialPoints*>(sp));
        }
    }

    return rtrn;
}
std::vector<DDSpecialAttack*> DDCreature::GetSpecialAttacks()
{
    std::vector<DDSpecialAttack*> rtrn;

    for (DDSpecialProperty* sp : specialProperties)
    {
        if (sp->GetType() == attackProperty)
        {
            rtrn.push_back(dynamic_cast<DDSpecialAttack*>(sp));
        }
    }

    return rtrn;
}
void DDCreature::AddSpell (DDSpell *spell) { spells.push_back(spell); }

DDSubClass::DDSubClass (QString n) { this->name = n; }
DDSubClass::DDSubClass (QString n, std::vector<LevelFeature*> features)
{
    this->name = n;
    this->subclassLevelFeatures = features;
}
DDSubClass::DDSubClass (QString n, std::vector<LevelSpell*> spells, std::vector<LevelFeature*> features)
{
    this->name = n;
    this->subclassSpells = spells;
    this->subclassLevelFeatures = features;
}
QString DDSubClass::GetName() { return name; }
DDSpell* DDSubClass::GetSpellByLevel(int level)
{
    for (LevelSpell* spell : subclassSpells)
    {
        if (spell->level == level)
        {
            return spell->spell;
        }
    }

    return nullptr;
}
DDSpecialProperty* DDSubClass::GetFeatureByLevel(int level)
{
    for (LevelFeature* feature : subclassLevelFeatures)
    {
        if (feature->level == level)
        {
            return feature->feature;
        }
    }

    return nullptr;
}

DDClass::DDClass (QString n, dice hD, std::vector<armourType> aP, bool m, stats *sT, skills *prof, DDSubClass *sC)
{
    this->name = n;
    this->hitDie = hD;
    this->armourProficiencies = aP;
    this->martialProficent = m;
    this->savingThrowProficiencies[0] = *sT;
    this->savingThrowProficiencies[1] = *(sT + 1);
    this->possibleSkillProfinciencies[0] = *(prof);
    this->possibleSkillProfinciencies[1] = *(prof + 1);
    this->possibleSkillProfinciencies[2] = *(prof + 2);
    this->possibleSkillProfinciencies[3] = *(prof + 3);
    this->possibleSkillProfinciencies[4] = *(prof + 4);
    this->possibleSkillProfinciencies[5] = *(prof + 5);
    this->subClass = sC;
    this->spellsUnlocked = false;
}
DDClass::DDClass (QString n, dice hD, std::vector<armourType> aP, bool m, stats *sT, skills *prof, DDSubClass *sC, stats s)
{
    this->name = n;
    this->hitDie = hD;
    this->armourProficiencies = aP;
    this->martialProficent = m;
    this->savingThrowProficiencies[0] = *sT;
    this->savingThrowProficiencies[1] = *(sT + 1);
    this->possibleSkillProfinciencies[0] = *(prof);
    this->possibleSkillProfinciencies[1] = *(prof + 1);
    this->possibleSkillProfinciencies[2] = *(prof + 2);
    this->possibleSkillProfinciencies[3] = *(prof + 3);
    this->possibleSkillProfinciencies[4] = *(prof + 4);
    this->possibleSkillProfinciencies[5] = *(prof + 5);
    this->subClass = sC;
    this->spellsUnlocked = true;
    this->spellStat = s;
}
DDClass::DDClass (QString n, dice hD, std::vector<armourType> aP, bool m, stats *sT, skills *prof, std::vector<LevelFeature*> lF, DDSubClass *sC, bool spells)
{
    this->name = n;
    this->hitDie = hD;
    this->armourProficiencies = aP;
    this->martialProficent = m;
    this->savingThrowProficiencies[0] = *sT;
    this->savingThrowProficiencies[1] = *(sT + 1);
    this->possibleSkillProfinciencies[0] = *(prof);
    this->possibleSkillProfinciencies[1] = *(prof + 1);
    this->possibleSkillProfinciencies[2] = *(prof + 2);
    this->possibleSkillProfinciencies[3] = *(prof + 3);
    this->possibleSkillProfinciencies[4] = *(prof + 4);
    this->possibleSkillProfinciencies[5] = *(prof + 5);
    this->levelFeatures = lF;
    this->subClass = sC;
    this->spellsUnlocked = spells;
}
QString DDClass::GetName() { return name; }
dice DDClass::GetHitDie() { return hitDie; }
int DDClass::SpellSlotsAtLevel (int spellLevel, int playerLevel) { return spellSlotsPerLevel[playerLevel][spellLevel]; }
QString DDClass::GetArmourProficenciesText()
{
    QString rtrn;
    for (int i = 0; i < (int)armourProficiencies.size(); i++)
    {
        rtrn += ArmourTypeText(armourProficiencies[i]);
        if (i < (int)armourProficiencies.size() - 1)
        {
            rtrn += ", ";
        }
    }
    return rtrn;
}
armourType DDClass::GetArmourProficiency (int index) { return armourProficiencies[index]; }
bool DDClass::ProficientInArmour (armourType armour)
{
    for (armourType a : armourProficiencies)
    {
        if (a == armour)
        {
            return true;
        }
    }
    return false;
}
bool DDClass::ProficientInMartial () { return martialProficent; }
stats DDClass::GetSavingThrowProfiency(int index) { return savingThrowProficiencies[index]; }
skills DDClass::GetSkillProficency(int index) { return possibleSkillProfinciencies[index]; }
LevelFeature* DDClass::GetLevelFeature(int index) { return levelFeatures[index]; }
DDSpecialProperty* DDClass::GetLevelFeatureByLevel (int level)
{
    for (LevelFeature* feature : levelFeatures)
    {
        if (feature->level == level)
        {
            return feature->feature;
        }
    }

    return nullptr;
}
DDSubClass* DDClass::GetSubClass() { return subClass; }
bool DDClass::CanCastSpells() { return spellsUnlocked; }
ushort DDClass::GetLevelFeatureCount() { return levelFeatures.size(); }
stats DDClass::GetSpellStat() { return spellStat; }

DDSubRace::DDSubRace(QString n, std::vector<AbilityScoreImprovement*> aS, std::vector<DDSpecialProperty*> sP)
{
    this->name = n;
    this->abilityScores = aS;
    this->specialProperties = sP;
}
DDSubRace::DDSubRace(QString n) { this->name = n; }
DDSubRace::DDSubRace(QString n, AbilityScoreImprovement *aS)
{
    this->name = n;
    this->abilityScores.push_back(aS);
}
QString DDSubRace::GetName() { return name; }
AbilityScoreImprovement* DDSubRace::GetStatImprovement(int index) { return abilityScores[index]; }
DDSpecialProperty* DDSubRace::GetSpecialProperty(int index) { return specialProperties[index]; }
void DDSubRace::AddSpecialProperty(DDSpecialProperty* s) { specialProperties.push_back(s); }

DDRace::DDRace(QString n, std::vector<AbilityScoreImprovement*> aS, std::vector<DDSpecialProperty*> sP, DDSubRace* sR, size s, creatureType t)
{
    this->name = n;
    this->abilityScores = aS;
    this->specialProperties = sP;
    this->subRace = sR;
    this->raceSize = s;
    this->raceType = t;
}
DDRace::DDRace(QString n, AbilityScoreImprovement *aS, DDSubRace* sR, size s, creatureType t)
{
    this->name = n;
    this->abilityScores.push_back(aS);
    this->subRace = sR;
    this->raceSize = s;
    this->raceType = t;
}
QString DDRace::GetName() { return name; }
AbilityScoreImprovement* DDRace::GetStatImprovement(int index) { return abilityScores[index]; }
DDSpecialProperty* DDRace::GetSpecialProperty(int index) { return specialProperties[index]; }
DDSubRace* DDRace::GetSubRace() { return subRace; }
size DDRace::GetSize() { return raceSize; }
creatureType DDRace::GetCreatureType() { return raceType; }
void DDRace::AddSpecialProperty(DDSpecialProperty* addProperty) { specialProperties.push_back(addProperty); }
ushort DDRace::GetSpecialPropertyCount() { return specialProperties.size(); }

ushort InventoryNode::inventoryCount = 0;

InventoryNode::InventoryNode(InventoryNode *prev, DDObject *obj)
{
    this->connections[0] = prev;
    this->object = obj;
    this->state = bag;
    inventoryCount++;
}
InventoryNode::InventoryNode(InventoryNode *prev, InventoryNode *next, DDObject *obj)
{
    this->connections[0] = prev;
    this->connections[1] = next;
    this->object = obj;
    this->state = bag;
    inventoryCount++;
}
InventoryNode::InventoryNode()
{
    this->object = nullptr;
    this->connections[0] = nullptr;
    this->connections[1] = nullptr;
}
InventoryNode::~InventoryNode()
{
    delete object;
    inventoryCount--;
}
DDObject* InventoryNode::GetObject() { return object; }
InventoryNode* InventoryNode::Next() { return connections[1]; }
InventoryNode* InventoryNode::Prev() { return connections[0]; }
InventoryNode* InventoryNode::Next(int i) { InventoryNode *rtrn; for (int o = 0; o < i; o++) { rtrn = rtrn->Next(); } return rtrn; }
InventoryNode* InventoryNode::Prev(int i) { InventoryNode *rtrn; for (int o = 0; o < i; o++) { rtrn = rtrn->Prev(); } return rtrn; }
void InventoryNode::SetNext(InventoryNode* next) { connections[1] = next; }
void InventoryNode::SetPrev(InventoryNode* prev) { connections[0] = prev; }
ushort InventoryNode::Count() { return inventoryCount; }

DDPlayerClass::DDPlayerClass(DDClass *c, ushort l) :
    DDClass(*c)
{
    this->level = l;
    this->hitDice = new DDDice(hitDie, level, 0);
}
ushort DDPlayerClass::GetLevel() { return level; }
DDDice* DDPlayerClass::GetHitDie() { return hitDice; }
QString DDPlayerClass::GetHitDieText() { return hitDice->ToString();}
void DDPlayerClass::LevelUp() { level++; }
void DDPlayerClass::UpdateHitDie() { this->hitDice->SetCount(level); }
void DDPlayerClass::UpdateHitDie(short conBonus) { this->hitDice->SetCount(level); this->hitDice->SetModifier(conBonus); }
int DDPlayerClass::SpellSlotsAtLevel (int spellLevel) { return spellSlotsPerLevel[level][spellLevel]; }

DDPlayerCharacter::DDPlayerCharacter(QString n, alignment a, ushort hp, ushort stt[6], std::vector<enum skills> skprof, std::vector<enum stats> svprof,
        std::vector<damageType> dI, std::vector<damageType> dR, std::vector<damageType> dV, std::vector<DDSpecialProperty*> sp, std::vector<DDSpell*> spll, std::vector<language> lng,
        ushort ag, DDRace* r, std::vector<DDPlayerClass*> cls, float g)
{
    this->creatureSize = r->GetSize();
    this->type = r->GetCreatureType();
    this->align = a;
    this->maxHp = hp;
    this->hp = maxHp;
    this->ac = 10 + stt[dexterity];
    for (int i = 0; i < 6; i++)
    {
        stats[i] = stt[i];
        savingThrows[i] = (stt[i] - 10) / 2;
    }

    for (DDPlayerClass *pc : cls)
    {
        this->proficiencyBonus += pc->GetLevel();
    }
    this->proficiencyBonus = GetProficincyFromLevel(proficiencyBonus);
    this->skillProficiencies = skprof;
    this->savingThrowProficiencies = svprof;
    this->initBonus = (stats[dexterity] - 10) / 2;
    this->dmgImmunities = dI;
    this->dmgResistances = dR;
    this->dmgVulnarabilities = dV;
    this->specialProperties = sp;
    this->spells = spll;
    this->languages = lng;

    this->name = n;
    this->age = ag;
    this->race = r;
    this->classes = cls;

    bool hdInit = false;
    for (int i = 0; i < (int)classes.size(); i++)
    {
        classes[i]->UpdateHitDie((stats[constitution] - 10) / 2);
        if (hdInit)
        {
            hitDie->SetNext(classes[i]->GetHitDie());
        }
        else
        {
            hitDie = classes[i]->GetHitDie();
        }
    }

    this->speed[walking] = 30;
    this->speed[climbing] = 15;
    this->speed[swimming] = 15;
    this->speed[flying] = 0;

    this->gold = g;

    this->inventory = new InventoryNode();

    GetSkillsFromStats();

    this->passivePerception = 10 + skills[perception];

    this->unarmed = new DDWeapon("Fists", "Its your fists", common, small, 0, improvised, new DDDamageDice(d4, 1, this->GetStatModifier(strength), bludgeoning), std::vector<weaponProperties>(), false, 0, 5);
}
DDPlayerCharacter::DDPlayerCharacter(QString n, alignment a, ushort hp, ushort stt[6], std::vector<enum skills> skprof, std::vector<enum stats> svprof,
        std::vector<DDSpecialProperty*> sp, std::vector<DDSpell*> spll, std::vector<language> lng, ushort ag, DDRace* r, std::vector<DDPlayerClass*> cls, float g)
{
    this->creatureSize = r->GetSize();
    this->type = r->GetCreatureType();
    this->align = a;
    this->maxHp = hp;
    this->hp = maxHp;
    this->ac = 10 + ((stt[dexterity] - 10) / 2);

    for (int i = 0; i < 6; i++)
    {
        stats[i] = stt[i];
        savingThrows[i] = (stt[i] - 10) / 2;
    }

    for (DDPlayerClass *pc : cls)
    {
        this->proficiencyBonus += GetProficincyFromLevel(pc->GetLevel());
    }

    this->proficiencyBonus = GetProficincyFromLevel(proficiencyBonus);
    this->skillProficiencies = skprof;
    this->savingThrowProficiencies = svprof;
    this->initBonus = (stats[dexterity] - 10) / 2;
    this->specialProperties = sp;
    this->spells = spll;
    this->languages = lng;

    this->name = n;
    this->age = ag;
    this->race = r;
    this->classes = cls;

    bool hdInit = false;
    for (int i = 0; i < (int)classes.size(); i++)
    {
        classes[i]->UpdateHitDie((stats[constitution] - 10) / 2);
        if (hdInit)
        {
            hitDie->SetNext(classes[i]->GetHitDie());
        }
        else
        {
            hitDie = classes[i]->GetHitDie();
        }
    }

    this->speed[walking] = 30;
    this->speed[climbing] = 15;
    this->speed[swimming] = 15;
    this->speed[flying] = 0;
    this->gold = g;
    this->inventory = new InventoryNode();

    GetSkillsFromStats();

    this->passivePerception = 10 + skills[perception];

    this->unarmed = new DDWeapon("Fists", "Its your fists", common, small, 0, improvised, new DDDamageDice(d4, 1, this->GetStatModifier(strength), bludgeoning), std::vector<weaponProperties>(), false, 0, 5);
}
DDPlayerCharacter::DDPlayerCharacter(QString n, alignment a, ushort hp, ushort stt[6], std::vector<enum skills> skprof, std::vector<enum stats> svprof, std::vector<DDSpecialProperty*> sp,
        std::vector<DDSpell*> spll, std::vector<language> lng, ushort ag, DDRace* r, DDPlayerClass* cls, float g)
{
    this->creatureSize = r->GetSize();
    this->type = r->GetCreatureType();
    this->align = a;
    this->maxHp = hp;
    this->hp = maxHp;
    this->ac = 10 + stt[dexterity];
    for (int i = 0; i < 6; i++)
    {
        stats[i] = stt[i];
        savingThrows[i] = (stt[i] - 10) / 2;
    }

    this->proficiencyBonus = GetProficincyFromLevel(cls->GetLevel());
    this->skillProficiencies = skprof;
    this->savingThrowProficiencies = svprof;
    this->initBonus = (stats[dexterity] - 10) / 2;
    this->specialProperties = sp;
    this->spells = spll;
    this->languages = lng;

    this->name = n;
    this->age = ag;
    this->race = r;
    this->classes.push_back(cls);

    bool hdInit = false;
    for (int i = 0; i < (int)classes.size(); i++)
    {
        classes[i]->UpdateHitDie((stats[constitution] - 10) / 2);
        if (hdInit)
        {
            hitDie->SetNext(classes[i]->GetHitDie());
        }
        else
        {
            hitDie = classes[i]->GetHitDie();
        }
    }

    this->speed[walking] = 30;
    this->speed[climbing] = 15;
    this->speed[swimming] = 15;
    this->speed[flying] = 0;

    this->gold = g;

    this->inventory = new InventoryNode();

    GetSkillsFromStats();

    this->passivePerception = 10 + skills[perception];

    this->unarmed = new DDWeapon("Fists", "Its your fists", common, small, 0, improvised, new DDDamageDice(d4, 1, this->GetStatModifier(strength), bludgeoning), std::vector<weaponProperties>(), false, 0, 5);
}
ushort DDPlayerCharacter::GetAge() { return age; }
ushort DDPlayerCharacter::GetPassivePerception() { return passivePerception; }
DDRace* DDPlayerCharacter::GetRace() { return race; }
DDPlayerClass* DDPlayerCharacter::GetClass(int index) { return classes[index]; }
InventoryNode* DDPlayerCharacter::GetHeadInventoryNode() { return inventory; }
float DDPlayerCharacter::GetGold() { return gold; }
DDDice* DDPlayerCharacter::GetHitDie(int index) { return classes[index]->GetHitDie(); }
std::vector<DDDice*> DDPlayerCharacter::GetHitDice()
{
    std::vector<DDDice*> rtrn;
    DDDice *current = hitDie;

    do
    {
        rtrn.push_back(current);
        current = current->Next();
    } while (current->MoreDice());

    return rtrn;
}
ushort DDPlayerCharacter::GetClassCount() { return classes.size(); }
std::vector<DDArmour*> DDPlayerCharacter::GetArmours()
{
    std::vector<DDArmour*> rtrn;
    InventoryNode *inv = inventory->Next();

    while (inv != nullptr)
    {
        if (inv->GetObject()->GetType() == armour)
        {
            rtrn.push_back(dynamic_cast<DDArmour*>(inv->GetObject()));
        }
        inv = inv->Next();
    }
    return rtrn;
}
std::vector<DDWeapon*> DDPlayerCharacter::GetWeapons()
{
    std::vector<DDWeapon*> rtrn;
    InventoryNode *inv = inventory->Next();

    while (inv != nullptr)
    {
        if (inv->GetObject()->GetType() == weapon)
        {
            rtrn.push_back(dynamic_cast<DDWeapon*>(inv->GetObject()));
        }
        inv = inv->Next();
    }
    return rtrn;
}
std::vector<DDShield*> DDPlayerCharacter::GetShields()
{
    std::vector<DDShield*> rtrn;
    InventoryNode *inv = inventory->Next();

    while (inv != nullptr)
    {
        if (inv->GetObject()->GetType() == shield)
        {
            rtrn.push_back(dynamic_cast<DDShield*>(inv->GetObject()));
        }
        inv = inv->Next();
    }
    return rtrn;
}
void DDPlayerCharacter::AddItem(DDObject* item)
{
    InventoryNode *next = inventory->Next();
    InventoryNode *newNode = new InventoryNode(inventory, next, item);
    inventory->SetNext(newNode);
    if (next != nullptr)
    {
        next->SetPrev(newNode);
    }
}
void DDPlayerCharacter::RemoveItem(int index)
{
    InventoryNode *remove = inventory->Next(index);
    remove->Prev()->SetNext(remove->Next());
    remove->Next()->SetPrev(remove->Prev());
    remove->~InventoryNode();
}
DDWeapon* DDPlayerCharacter::GetUnarmed() { return unarmed; }
void DDPlayerCharacter::SetUnarmed(DDWeapon* u) { unarmed = u; }
